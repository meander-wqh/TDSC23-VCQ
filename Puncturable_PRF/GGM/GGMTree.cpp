//
// Created by bob on 2021/3/12.
//

#include "../../include/GGM/GGMTree.h"
GGMTree::GGMTree(int num_node) {
    this->level = ceil(log2(num_node));
}

void GGMTree::derive_key_from_tree(uint8_t *current_key, int offset, int start_level, int target_level) {
    uint8_t next_key[AES_BLOCK_SIZE];
    // does not need to derive
    if(start_level == target_level) return;
    // derive tag
    for (int k = start_level; k > target_level; --k) {
        int k_bit = (offset & (1 << (k - 1))) >> (k - 1);
        key_derivation((uint8_t*) &k_bit, sizeof(int),
                       current_key, AES_BLOCK_SIZE,
                       next_key);
        memcpy(current_key, next_key, AES_BLOCK_SIZE);
    }
}

//递归深度太深
// vector<GGMNode> GGMTree::min_coverage(const vector<GGMNode>& node_list) {
//     vector<GGMNode> next_level_node;

//     for (int i = 0; i < node_list.size(); ++i) {
//         auto node1 = node_list[i];

//         if(i + 1 == node_list.size()) {
//             next_level_node.emplace_back(node1);
//         } else {
//             auto node2 = node_list[i + 1];
//             // same parent in the binary path
//             if(((node1.index >> 1) == (node2.index >> 1)) && (node1.level == node2.level)) {
//                 next_level_node.emplace_back(GGMNode(node1.index >> 1, node1.level - 1));
//                 i++;
//             } else {
//                 next_level_node.emplace_back(node1);
//             }
//         }
//     }

//     // no merge return
//     if (next_level_node.size() == node_list.size() || next_level_node.empty()) {
//         return node_list;
//     }

//     return min_coverage(next_level_node);
// }

//迭代版本
vector<GGMNode> GGMTree::min_coverage(const vector<GGMNode>& node_list) {
    vector<GGMNode> current_level_node = node_list;

    while (true) {
        vector<GGMNode> next_level_node;
        size_t i = 0;
        
        // 遍历当前节点列表
        while (i < current_level_node.size()) {
            auto node1 = current_level_node[i];
            
            if (i + 1 == current_level_node.size()) {
                // 如果是最后一个节点，直接加入到下一层
                next_level_node.push_back(node1);
                break;
            } else {
                auto node2 = current_level_node[i + 1];
                // 检查是否可以合并
                if (((node1.index >> 1) == (node2.index >> 1)) && (node1.level == node2.level)) {
                    // 合并两个节点，加入合并后的节点
                    next_level_node.push_back(GGMNode(node1.index >> 1, node1.level - 1));
                    i++; // 跳过下一个节点
                } else {
                    // 不合并，直接将节点加入
                    next_level_node.push_back(node1);
                }
            }
            i++;
        }

        // 如果没有发生合并，退出循环
        if (next_level_node.size() == current_level_node.size() || next_level_node.empty()) {
            return current_level_node;
        }

        // 更新为下一层节点
        current_level_node = next_level_node;
    }
}

int GGMTree::get_level() const {
    return level;
}