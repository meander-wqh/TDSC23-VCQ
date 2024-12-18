#include "../include/VCQ/Client.h"
#include "../include/VCQ/Server.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    Client client;
    Server server;
    /*读数据集*/

    // PuncPRF Setup
    uint8_t *key = (unsigned char*) "0123456789123456";
    PuncPRF::SetUp(key, 16);

    // 打开文件
    ifstream file("../dataset/Enron_linkedList/0.txt");

    // 检查文件是否成功打开
    if (!file.is_open()) {
        cerr << "无法打开文件!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);  // 使用stringstream来分割行内容
        string id, counter;
        
        // 读取id和counter
        if (!(ss >> id >> counter)) {
            cerr << "无法读取id或计数器!" << endl;
            continue;  // 继续读取下一行
        }

        // 输出id和counter
        cout << "ID: " << id << ", Counter: " << counter << endl;

        vector<string> keywords;
        string temp;
        
        // 读取剩下的列，并存入vector<string>
        while (ss >> temp) {
            keywords.push_back(temp);
        }

        std::set<A1Element> A1;
        A2Element A2;
        client.Update(id, keywords, true, A1, A2);
        server.Update(A1, A2);
    }
    file.close();  // 关闭文件

    /*Search*/
    std::vector<std::string> keywords = {"brief", "join"};
    St_1 st_1;
    int st_2;
    std::string x = client.GenerateSt(keywords, st_1, st_2);

    std::set<R_Element> R_;
    std::string proof;
    std::string proof_;
    server.Search(st_1, st_2, R_, proof, proof_);
    client.Search(keywords, x, R_);
    
    return 0;
}