//
// Created by bob on 2021/3/12.
//

#ifndef PUNCTURABLE_PRF_GGMNODE_H
#define PUNCTURABLE_PRF_GGMNODE_H

extern "C" {
#include "Utils.h"
}

class GGMNode {
public:
    int index;
    int level;
    uint8_t key[AES_BLOCK_SIZE]{};

    GGMNode(int index, int level) {
        this->index = index;
        this->level = level;
    }

    GGMNode(int index, int level, uint8_t *key) {
        this->index = index;
        this->level = level;
        memcpy(this->key, key, AES_BLOCK_SIZE);
    }
};


#endif //PUNCTURABLE_PRF_GGMNODE_H
