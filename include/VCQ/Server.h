#ifndef SERVER_H
#define SERVER_H
#include "common.h"
#include <unordered_map>
#include <set>

class Server{
    public:
        std::unordered_map<std::string, A1Element> T_i;
        std::unordered_map<std::string, A2Element> T_f;
        void Update(std::set<A1Element>& A1, A2Element& A2);
};


#endif