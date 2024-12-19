#include "../include/Puncturable_PRF/Punc_PRF.h"

GGMTree* PuncPRF::tree = nullptr;
uint8_t* PuncPRF::key = nullptr;
unordered_map<int, uint8_t*> PuncPRF::keys;
// vector<GGMNode> PuncPRF::node_list;
// vector<GGMNode> PuncPRF::remain_node;

void PuncPRF::SetUp(uint8_t* key, int key_len){
    PuncPRF::key = new uint8_t(key_len);
    memcpy(PuncPRF::key, key, key_len);
    tree = new GGMTree(GGM_SIZE);
}

// vector<GGMNode> PuncPRF::Punc(vector<int> delete_pos){
//     vector<int> pos(GGM_SIZE);
//     std::iota(pos.begin(), pos.end(), 0);
//     // for (int i = 0; i < GGM_SIZE; ++i) {
//     //     pos.emplace_back(i);
//     //     std::cout<<i<<std::endl;
//     // }
//     vector<int> remain_pos;
//     set_difference(pos.begin(), pos.end(),
//                    delete_pos.begin(), delete_pos.end(),
//                    inserter(remain_pos, remain_pos.begin()));
    
    

//     PuncPRF::node_list.reserve(remain_pos.size()); //preallocate memory for vector
//     for (int pos : remain_pos) {
//         PuncPRF::node_list.emplace_back(GGMNode(pos, tree->get_level()));
//     }
//     PuncPRF::remain_node = tree->min_coverage(PuncPRF::node_list);

//     for(auto & i : PuncPRF::remain_node) {
//         memcpy(i.key, PuncPRF::key, AES_BLOCK_SIZE);
//         // for(int j=0;j<16;j++){
//         //     printf ( "%02x ", i.key[j]);
//         // }
//         // cout<<endl;
//         GGMTree::derive_key_from_tree(i.key, i.index, i.level, 0);
//         // for(int j=0;j<16;j++){
//         //     printf ( "%02x ", i.key[j]);
//         // }
//         // cout<<endl;
//     }
// }

vector<GGMNode> PuncPRF::Punc(vector<int> delete_pos){
    // for(int i=0;i< delete_pos.size();i++){
    //     cout << delete_pos[i] << " ";
    // }
    vector<GGMNode> remain_node;
    //使得node_list离开作用域就释放内存
    {
        std::vector<GGMNode> node_list;
        //使得remain_pos离开作用域就释放内存
        {
            vector<int> remain_pos;
            //使得pos离开作用域就释放内存
            {
                vector<int> pos(GGM_SIZE);
                std::iota(pos.begin(), pos.end(), 0);
                // for(int i=0;i<delete_pos.size();i++){
                //     cout<<delete_pos[i]<<" ";
                // }
                // cout<<endl;

                //delete_pos一定要是有序的！
                std::sort(delete_pos.begin(), delete_pos.end());
                set_difference(pos.begin(), pos.end(),
                            delete_pos.begin(), delete_pos.end(),
                            inserter(remain_pos, remain_pos.begin()));
            }
            node_list.reserve(remain_pos.size()); //preallocate memory for vector
            // cout<<"remain_pos.size(): "<<remain_pos.size()<<endl;
            for (int pos : remain_pos) {
                node_list.emplace_back(GGMNode(pos, tree->get_level()));
            }
        }
        remain_node = tree->min_coverage(node_list);
    }

    for(auto & i : remain_node) {
        memcpy(i.key, PuncPRF::key, AES_BLOCK_SIZE);
        GGMTree::derive_key_from_tree(i.key, i.index, i.level, 0);
        // for (int j = 0 ; j <16; ++j){
        //         printf ( "%02x ",i.key[j]);
        // }
        // cout << endl;
    }
    return remain_node;
}

void PuncPRF::PPRF_compute_all_keys(const vector<GGMNode>& remain_node) {
    for (auto& pair : PuncPRF::keys) {
        free(pair.second);
    }
    PuncPRF::keys.clear();
    int level = tree->get_level();
    for(GGMNode node : remain_node) {
        for (int i = 0; i < pow(2, level - node.level); ++i) {
            int offset = ((node.index) << (level - node.level)) + i;
            uint8_t derive_key[AES_BLOCK_SIZE];
            memcpy(derive_key, node.key, AES_BLOCK_SIZE);
            // for(int i=0;i<16;i++){
            //     printf ( "%02x ",node.key[i]);
            // }
            GGMTree::derive_key_from_tree(derive_key, offset, level - node.level, 0);
            if(PuncPRF::keys.find(offset) == PuncPRF::keys.end()) {
                PuncPRF::keys[offset] = (uint8_t*) malloc(AES_BLOCK_SIZE);
                memcpy(PuncPRF::keys[offset], derive_key, AES_BLOCK_SIZE);
//                for (int j = 0 ; j <16; ++j){
//                    printf ( "%02x ",keys[offset][j]);
//                }
//                cout << endl;
            }
        }
    }
}

bool PuncPRF::PPRF_Eval(int msg){
    if(PuncPRF::keys.find(msg) == PuncPRF::keys.end()){
        cout << "stop at punctured point !" << endl;
        return false;
    }
    else{
        cout <<"Original pseudo random value of "<< msg << " is : " << endl;
        for (int j = 0 ; j <16; ++j){
            printf ( "%02x ",PuncPRF::keys[msg][j]);
        }
        cout << endl ;
    }
    return true;
}