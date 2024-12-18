//
// Created by bob on 2021/3/12.
//

#ifndef PUNCTURABLE_PRF_GGMTREE_H
#define PUNCTURABLE_PRF_GGMTREE_H

#include <bitset>
#include <cmath>
#include <cstring>
#include <vector>

#include "GGMNode.h"
extern "C" {
#include "Utils.h"
}

using namespace std;

class GGMTree {
private:
    int level;

public:
    explicit GGMTree(int num_node);
    void static derive_key_from_tree(uint8_t *current_key, int offset, int start_level, int target_level);
    vector<GGMNode> min_coverage(const vector<GGMNode>& node_list);
    int get_level() const;
};


#endif //PUNCTURABLE_PRF_GGMTREE_H
