#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../include/GGM/GGMTree.h"
#include "../include/Puncturable_PRF/Punc_PRF.h"

using  namespace  std;

int main() {
    /*Setup  */
    uint8_t *key = (unsigned char*) "0123456789123456";
    PuncPRF::SetUp(key, 16);

    /*Punc */
    vector<int> delete_pos;
    delete_pos.emplace_back(1);
    std::vector<GGMNode> remain_node = PuncPRF::Punc(delete_pos);
    
    /*Eval */
    PuncPRF::PPRF_compute_all_keys(remain_node);// precompute all keys of nodes
    PuncPRF::PPRF_Eval(1);
    PuncPRF::PPRF_Eval(65500);
    PuncPRF::PPRF_Eval(0);

    return 0;
}
