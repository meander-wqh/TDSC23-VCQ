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
        std::unordered_map<std::string, int> F_2; //simulate F_2, input keyword, output an integer 
        int counter = 0; //counter for each w, which is the integer of w in F_2
        void Update(std::string id, std::vector<std::string> w, bool op, std::set<A1Element>& A1, A2Element& A2);
        Client();
};  


#endif