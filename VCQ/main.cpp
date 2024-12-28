#include "../include/VCQ/Client.h"
#include "../include/VCQ/Server.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

uint64_t timeSinceEpochMillisec() {//截取以纪元时间为单位获取当前时间戳，以微秒为单位

  using namespace std::chrono;
  return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}

int main(int argc, char *argv[]){
    Client client;
    Server server;

    int Number = 40000;
    int Counter = 0;
    std::set<std::string> wSet;

    /*读数据集*/
    uint64_t start_time =  timeSinceEpochMillisec();

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
    int c = 0;
    while (getline(file, line)) {
        // if(c == 100){
        //     break;
        // }
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

        wSet.insert(keywords.begin(), keywords.end());

        std::set<A1Element> A1;
        A2Element A2;
        client.Update(id, keywords, true, A1, A2);
        server.Update(A1, A2);

        Counter += std::stoi(counter);
        if(Counter >= Number){
            break;
        }
        // c++;
    }
    file.close();  // 关闭文件

    uint64_t end_time =  timeSinceEpochMillisec();
    cout<<"Keywords number: "<<wSet.size()<<endl;
    std::cout << "Update time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;



    /*Search*/
    std::vector<std::string> candidate_keywords = {"pdt", "0700", "phillip", "k", "2000", "enron", "ascii", "us", "7bit", "mime"};
    std::vector<std::string> keywords = {"pdt", "0700"};
    {
    St_1 st_1;
    int st_2;
    start_time =  timeSinceEpochMillisec();
    std::string x = client.GenerateSt(keywords, st_1, st_2);

    std::set<R_Element> R_;
    std::string proof;
    std::string proof_;
    server.Search(st_1, st_2, R_, proof, proof_);
    client.Search(keywords, x, R_);

    cout<<"search finish"<<endl;
    end_time =  timeSinceEpochMillisec();
    std::cout << "Search time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;

    /*Verify*/
    start_time =  timeSinceEpochMillisec();
    client.Verify(R_, x, proof, proof_);
    end_time =  timeSinceEpochMillisec();
    std::cout << "Verify time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;
    }


    {
    keywords = {"pdt", "0700", "phillip", "k"};
    St_1 st_1;
    int st_2;
    start_time =  timeSinceEpochMillisec();
    std::string x = client.GenerateSt(keywords, st_1, st_2);

    std::set<R_Element> R_;
    std::string proof;
    std::string proof_;
    server.Search(st_1, st_2, R_, proof, proof_);
    client.Search(keywords, x, R_);

    cout<<"search finish"<<endl;
    end_time =  timeSinceEpochMillisec();
    std::cout << "Search time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;

    /*Verify*/
    start_time =  timeSinceEpochMillisec();
    client.Verify(R_, x, proof, proof_);
    end_time =  timeSinceEpochMillisec();
    std::cout << "Verify time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;
    }

    {
    keywords = {"pdt", "0700", "phillip", "k", "2000", "enron"};
    St_1 st_1;
    int st_2;
    start_time =  timeSinceEpochMillisec();
    std::string x = client.GenerateSt(keywords, st_1, st_2);

    std::set<R_Element> R_;
    std::string proof;
    std::string proof_;
    server.Search(st_1, st_2, R_, proof, proof_);
    client.Search(keywords, x, R_);

    cout<<"search finish"<<endl;
    end_time =  timeSinceEpochMillisec();
    std::cout << "Search time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;

    /*Verify*/
    start_time =  timeSinceEpochMillisec();
    client.Verify(R_, x, proof, proof_);
    end_time =  timeSinceEpochMillisec();
    std::cout << "Verify time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;
    }


    {
    keywords = {"pdt", "0700", "phillip", "k", "2000", "enron", "ascii", "us"};
    St_1 st_1;
    int st_2;
    start_time =  timeSinceEpochMillisec();
    std::string x = client.GenerateSt(keywords, st_1, st_2);

    std::set<R_Element> R_;
    std::string proof;
    std::string proof_;
    server.Search(st_1, st_2, R_, proof, proof_);
    client.Search(keywords, x, R_);

    cout<<"search finish"<<endl;
    end_time =  timeSinceEpochMillisec();
    std::cout << "Search time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;

    /*Verify*/
    start_time =  timeSinceEpochMillisec();
    client.Verify(R_, x, proof, proof_);
    end_time =  timeSinceEpochMillisec();
    std::cout << "Verify time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;
    }


    {
    keywords = {"pdt", "0700", "phillip", "k", "2000", "enron", "ascii", "us", "7bit", "mime"};
    St_1 st_1;
    int st_2;
    start_time =  timeSinceEpochMillisec();
    std::string x = client.GenerateSt(keywords, st_1, st_2);

    std::set<R_Element> R_;
    std::string proof;
    std::string proof_;
    server.Search(st_1, st_2, R_, proof, proof_);
    client.Search(keywords, x, R_);

    cout<<"search finish"<<endl;
    end_time =  timeSinceEpochMillisec();
    std::cout << "Search time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;

    /*Verify*/
    start_time =  timeSinceEpochMillisec();
    client.Verify(R_, x, proof, proof_);
    end_time =  timeSinceEpochMillisec();
    std::cout << "Verify time: " <<(end_time - start_time) / 1000.0 << " ms" << std::endl;
    }



    return 0;
    
}