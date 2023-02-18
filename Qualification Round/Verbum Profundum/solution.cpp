#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;

    TrieNode(){
        children.resize(26);
    }
};

void insert(TrieNode* root, string key){

    TrieNode* traverse = root;

    for (int i = key.size() - 1; i >= 0; i--){

        if (traverse->children[key[i] - 'a'] == NULL)
            traverse->children[key[i] - 'a'] = new TrieNode();

        traverse = traverse->children[key[i] - 'a'];
    }

}

bool search(TrieNode* root, string key){
    
    TrieNode* traverse = root;

    for (int i = 0; i < (key.size()+1)/2; i++){
        if (traverse->children[key[i] - 'a'] == NULL)
            return false;

        traverse = traverse->children[key[i] - 'a'];
    }
    
    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TrieNode* root = new TrieNode();

    int n; cin >> n;
    vector<string> str_list;

    while (n--){
        string s; cin >> s;
        str_list.push_back(s);
        insert(root, s);        
    }

    int result = 0;
    for (string& str: str_list){
        if (search(root, str))
            result++;
    }

    cout << result << endl;

    return 0;
}
