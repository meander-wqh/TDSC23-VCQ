#ifndef SERVER_H
#define SERVER_H
#include "common.h"
#include "Crypto_Primitives.h"
#include <unordered_map>
#include <set>

class Server{
    public:
        std::unordered_map<std::string, A1Element> T_i;
        std::unordered_map<std::string, A2Element> T_f;
        std::unordered_map<std::string, EDB_cacheElement> EDB_cache;
        void Update(std::set<A1Element>& A1, A2Element& A2);
        void Search(St_1 st_1, int st_2, std::set<R_Element>& R_, std::string& proof, std::string& proof_);

        
};


#endif