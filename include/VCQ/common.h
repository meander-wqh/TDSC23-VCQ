#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <string>
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
    std::string vW;
    int lcntW;
    int valcntW;
    DictElement(){}
    DictElement(std::string vW, int lcntW, int valcntW){
        vW = vW;
        lcntW = lcntW;
        valcntW = valcntW;
    }
};

#endif