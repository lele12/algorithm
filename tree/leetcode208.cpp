#include <iostream>
#include <vector>

using namespace std;

struct Tree{

    bool is_end;
    Tree* child[26];
    Tree(bool is_end_= false):is_end(is_end_){
        for (int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};
class Trie{
public:
    Trie(){root = new Tree();};

    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
private:
    Tree* root;
};

void Trie::insert(string word){
    Tree* p = root;
    for (auto ch:word){

        if(p->child[ch-'a'] == nullptr){
            p->child[ch-'a'] = new Tree();
        }
        p = p->child[ch-'a'];
    }
    p->is_end = true;
}

bool Trie::search(string word){
    bool flag = true;
    Tree* p = root;
    for (auto ch:word){
        if(p->child[ch-'a'] == nullptr){
            flag = false;
            break;
        }
    }
    if (!p->is_end){
        flag = false;
    }
    return flag;
}

bool Trie::startsWith(string prefix){
    bool flag = true;
    Tree* p = root;
    for (auto ch:prefix){
        if(p->child[ch-'a'] == nullptr){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    Trie trie;
    trie.insert("app");
    cout << trie.search("app");
    return 0;
}