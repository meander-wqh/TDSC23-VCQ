#include "../include/VCQ/Server.h"

void Server::Update(std::set<A1Element>& A1, A2Element& A2){
    for(A1Element element : A1){
        T_i[element.tag] = element;
    }
    T_f[A2.tag] = A2;
    return;
}