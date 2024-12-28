#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <unordered_map>
#include <vector>
#include <set>

#include "Crypto_Primitives.h"
#include "common.h"



class Client{
    public:
        unordered_map<std::string, DictElement> Dict;
        std::string k_1; //K for prf
        std::unordered_map<std::string, int> F_2; //simulate F_2, input keyword, output an int

        int counter = 0; //counter for each w, which is the integer of w in F_2

        void Update(std::string id, std::vector<std::string> w, bool op, std::set<A1Element>& A1, A2Element& A2);

        std::string GenerateSt(std::vector<string>& keywords, St_1& st_1, int& st_2); //返回最少id的w

        std::set<std::string> Search(std::vector<std::string>& keywords, std::string& x, std::set<R_Element>& R_);

        void Verify(std::set<R_Element> R_, std::string x, std::string proof, std::string proof_);

        Client();
};  


#endif