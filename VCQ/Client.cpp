#include "../include/VCQ/Client.h"

Client::Client(){
    this->k_1 = Crypto_Primitives::get_rand(32);
}

void Client::Update(std::string id, std::vector<std::string> w, bool op, std::set<A1Element>& A1, A2Element& A2){
    std::string ranId = Crypto_Primitives::get_rand(16);
    std::vector<int> SID; 
    for(int i=0;i<w.size();i++){
        std::string vW = "";
        int lcntW;
        int valcntW;
        if(this->Dict.find(w[i]) == this->Dict.end()){
            vW = "1";
            lcntW = 0;
            valcntW = 0;
        }else{
            vW = Dict[w[i]].vW;
            lcntW = Dict[w[i]].lcntW;
            valcntW = Dict[w[i]].valcntW;
        }
        unsigned char kW_v[PRF_LEN];
        Crypto_Primitives::get_prf((unsigned char*)k_1.c_str(), (unsigned char*)(w[i]+vW).c_str(), (w[i]+vW).length(), kW_v);
        std::string skW_v((char*)kW_v, PRF_LEN);

        lcntW++;
        if(op){
            valcntW++;
        }else{
            valcntW--;
        }

        std::string tag = Crypto_Primitives::sha256((skW_v+std::to_string(lcntW)).c_str());

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
        
        A1.insert(A1Element(tag, sdata, svt));

        Dict[w[i]] = DictElement(skW_v, lcntW, valcntW);

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
