#include "../include/VCQ/Client.h"

Client::Client(){
    this->k_1 = Crypto_Primitives::get_rand(32);
}

void Client::Update(std::string id, std::vector<std::string> w, bool op, std::set<A1Element>& A1, A2Element& A2){
    std::string ranId = Crypto_Primitives::get_rand(16);
    std::vector<int> SID; 
    for(int i=0;i<w.size();i++){
        int vW;
        int lcntW;
        int valcntW;
        if(this->Dict.find(w[i]) == this->Dict.end()){
            vW = 1;
            lcntW = 0;
            valcntW = 0;
        }else{
            vW = Dict[w[i]].vW;
            lcntW = Dict[w[i]].lcntW;
            valcntW = Dict[w[i]].valcntW;
        }
        unsigned char kW_v[PRF_LEN];
        Crypto_Primitives::get_prf((unsigned char*)k_1.c_str(), (unsigned char*)(w[i] + std::to_string(vW)).c_str(), (w[i] + std::to_string(vW)).length(), kW_v);
        std::string skW_v((char*)kW_v, PRF_LEN);
        // cout<<skW_v<<endl;

        lcntW++;
        if(op){
            valcntW++;
        }else{
            valcntW--;
        }
        
        std::string tag = Crypto_Primitives::sha256((skW_v+std::to_string(lcntW)).c_str());
        // cout<<"tag: ";
        // Crypto_Primitives::print_string(tag);

        std::string temp = Crypto_Primitives::sha256((skW_v+std::to_string(lcntW)).c_str());
        char* a = (char*)temp.c_str();
        char b[SHA256_SIZE];
        Crypto_Primitives::padding(id + to_string(op), SHA256_SIZE, (unsigned char*)b);
        char data[SHA256_SIZE];
        Crypto_Primitives::string_xor(a, b, SHA256_SIZE, data);
        std::string sdata(data, SHA256_SIZE);

        unsigned char vt_1[PRF_LEN];
        unsigned char vt_2[PRF_LEN];
        unsigned char vt_3[PRF_LEN];
        unsigned char vt[PRF_LEN];
        Crypto_Primitives::get_prf((unsigned char*)k_1.c_str(), (unsigned char*)(w[i] + std::to_string(lcntW-1)).c_str(), PRF_LEN, vt_1);
        Crypto_Primitives::get_prf((unsigned char*)k_1.c_str(), (unsigned char*)(w[i] + std::to_string(lcntW)).c_str(), PRF_LEN, vt_1);
        Crypto_Primitives::get_prf((unsigned char*)k_1.c_str(), (unsigned char*)(id).c_str(), PRF_LEN, vt_1);
        Crypto_Primitives::string_xor((char*)vt_1, (char*)vt_2, PRF_LEN, (char*)vt);
        std::string svt((char*)vt, PRF_LEN);
        
        A1Element e(tag, sdata, svt);
        A1.insert(e);
        // cout<<A1.size()<<endl;

        Dict[w[i]] = DictElement(vW, lcntW, valcntW);

        if(op){
            if(F_2.find(w[i]) == F_2.end()){
                F_2[w[i]] = counter;
                counter ++;
            }
            SID.emplace_back(F_2[w[i]]);
        }
    }
    if(op){
        std::vector<GGMNode> K_SID = PuncPRF::Punc(SID);
        unsigned char vt[PRF_LEN];
        Crypto_Primitives::get_prf((unsigned char*)k_1.c_str(), (unsigned char*)(id).c_str(), PRF_LEN, vt);
        std::string svt((char*)vt, PRF_LEN);
        A2 = A2Element(id, K_SID, svt);
    }
}

std::string Client::GenerateSt(std::vector<std::string>& keywords, St_1& st_1, int& st_2){
    int leastValcnt = INT_MAX; // 更新最少的keyword
    std::string x; // 更新最少的keyword
    int index; // 更新最少的keyword的下标
    for(int i=0;i<keywords.size();i++){
        std::string w = keywords[i];
        if(Dict.find(w) == Dict.end()){
            return "";
        }
        DictElement e = Dict[w]; 
        if(e.valcntW < leastValcnt) {
            leastValcnt = e.valcntW;
            x = w;
            index = i;
        }
    }

    keywords.erase(keywords.begin() + index);

    std::string skX_v_1="";
    // cout << "vW: "<<Dict[x].vW <<endl;
    if(Dict[x].vW > 1){
        unsigned char kX_v_1[PRF_LEN];
        Crypto_Primitives::get_prf((unsigned char*)k_1.c_str(), (unsigned char*)(x + std::to_string(Dict[x].vW-1)).c_str(), PRF_LEN, kX_v_1);
        skX_v_1 = std::string((char*)kX_v_1, PRF_LEN);
    }

    std::string skX_v;
    unsigned char kX_v[PRF_LEN];
    Crypto_Primitives::get_prf((unsigned char*)k_1.c_str(), (unsigned char*)(x + std::to_string(Dict[x].vW)).c_str(), PRF_LEN, kX_v);
    skX_v = std::string((char*)kX_v, PRF_LEN);

    st_1.kX_v_1 = skX_v_1;
    // cout<<"skX_v_1:";
    // Crypto_Primitives::print_string(skX_v_1);
    // cout<<"skX_v:";
    st_1.kX_v = skX_v;
    // Crypto_Primitives::print_string(skX_v);
    st_1.lcntW = Dict[x].lcntW;
    st_2 = 1;

    return x;
}

std::set<std::string> Client::Search(std::vector<std::string> keywords, std::string x, std::set<R_Element> R_){
    std::set<std::string> R;
    Dict[x].vW = Dict[x].vW + 1;
    cout<<"R_.size(): "<< R_.size() <<endl;


    for(auto e : R_){
        // cout<<"e.id: "<< e.id <<endl;
        int flag = 1;
        PuncPRF::PPRF_compute_all_keys(e.data);
        for(int i=0;i<keywords.size();i++){
            if(PuncPRF::PPRF_Eval(F_2[keywords[i]])){
               flag = 0;
            }
        }
        if(flag){
            R.insert(e.id);
        }
    }

    cout<<"Res: ";
    for(auto r : R){
        cout<< r <<" ";
    }
    cout<<endl;
    return R;
}