#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <string>
#include <set>
#include "../Puncturable_PRF/Punc_PRF.h"

struct A1Element{
    std::string tag;
    std::string data;
    std::string vt;
    A1Element(){}
    A1Element(std::string tag, std::string data, std::string vt){
        tag = tag;
        data = data;
        vt = vt;
    }
    bool operator<(const A1Element& other) const {
        // Compare based on the fields of A1Element
        if (tag != other.tag) return tag < other.tag;
        if (data != other.data) return data < other.data;
        return vt < other.vt; // You can adjust the comparison as needed
    }
}; 

struct A2Element{
    std::string tag;
    std::vector<GGMNode> data;
    std::string vt;
    A2Element(){}
    A2Element(std::string tag, std::vector<GGMNode> data, std::string vt){
        tag = tag;
        data = data;
        vt = vt;
    }
};

struct DictElement{
    int vW;
    int lcntW;
    int valcntW;
    DictElement(){}
    DictElement(int vW, int lcntW, int valcntW){
        vW = vW;
        lcntW = lcntW;
        valcntW = valcntW;
    }
};

struct St_1{
    std::string kX_v_1;
    std::string kX_v;
    int lcntW;
    St_1(){}
    St_1(std::string kX_v_1, std::string kX_v, int lcntW){
        kX_v_1 = kX_v_1;
        kX_v = kX_v;
        lcntW = lcntW;
    }
};

struct EDB_cacheElement{
    std::set<std::string> ids;
    std::string proof;
    EDB_cacheElement(){}
    EDB_cacheElement(std::set<std::string> ids, std::string proof){
        ids = ids;
        proof = proof;
    }
};

struct R_Element{
    std::vector<GGMNode> data;
    std::string id;
    R_Element(){}
    R_Element(std::vector<GGMNode> data, std::string id){
        data = data;
        id = id;
    }
    bool operator<(const R_Element& other) const {
        return id < other.id;
    }
};

#endif