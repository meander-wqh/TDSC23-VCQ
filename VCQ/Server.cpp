#include "../include/VCQ/Server.h"

void Server::Update(std::set<A1Element>& A1, A2Element& A2){
    for(A1Element element : A1){
        T_i[element.tag] = element;
    }
    T_f[A2.tag] = A2;
    return;
}

void Server::Search(St_1 st_1, int st_2, std::set<R_Element>& R_, std::string& proof, std::string& proof_){
    int lcntX = st_1.lcntW;
    std::string tag = Crypto_Primitives::sha256((st_1.kX_v + std::to_string(lcntX)).c_str());
    proof = std::string(PRF_LEN, '\0');
    proof_ = std::string(PRF_LEN, '\0');
    std::set<std::string> R_add;
    std::set<std::string> R_del;
    while(T_i.find(tag) != T_i.end()){
        A1Element e = T_i[tag];
        
        char res[SHA256_SIZE];
        std::string temp = Crypto_Primitives::sha256((st_1.kX_v + std::to_string(lcntX)).c_str());
        Crypto_Primitives::string_xor((char*)temp.c_str(), (char*)e.data.c_str(), SHA256_SIZE, res);
        std::string sres = Crypto_Primitives::DePatch((unsigned char*)res, SHA256_SIZE); //id||op
        // cout<<"id||op: "<<sres<<endl;

        char temp_proof[PRF_LEN];
        Crypto_Primitives::string_xor((char*)proof.c_str(), (char*)e.vt.c_str(), SHA256_SIZE, temp_proof);
        proof = std::string(temp_proof, PRF_LEN);

        if(sres[sres.size()-1] == '1'){
            R_add.insert(sres.substr(0, sres.size()-1)); 
            // cout<<"id: "<<sres.substr(0, sres.size()-1)<<endl;
        }else{
            R_del.insert(sres.substr(0, sres.size()-1)); 
        }

        lcntX--;
        tag = Crypto_Primitives::sha256((st_1.kX_v + std::to_string(lcntX)).c_str());
    }

    if(st_1.kX_v_1.size()!=0){
        std::set<std::string> R_v_1 = EDB_cache[st_1.kX_v_1].ids;
        std::string proof_v_1 = EDB_cache[st_1.kX_v_1].proof;
        
        R_add.insert(R_v_1.begin(),R_v_1.end());
        char temp_proof[PRF_LEN];
        Crypto_Primitives::string_xor((char*)proof.c_str(), (char*)proof_v_1.c_str(), SHA256_SIZE, temp_proof);
        proof = std::string(temp_proof, PRF_LEN);
    }
    
    for(std::string id : R_del){
        if(R_add.find(id) != R_add.end()){
            R_add.erase(id);
        }
    }

    EDB_cache[st_1.kX_v] = EDB_cacheElement(R_add, proof);

    for(auto id : R_add){
        std::vector<GGMNode> data = T_f[id].data;
        std::string vt = T_f[id].vt;

        R_.insert(R_Element(data, id));

        char temp_proof[PRF_LEN];
        Crypto_Primitives::string_xor((char*)proof_.c_str(), (char*)vt.c_str(), SHA256_SIZE, temp_proof);
        proof_ = std::string(temp_proof, PRF_LEN);
    }

}

