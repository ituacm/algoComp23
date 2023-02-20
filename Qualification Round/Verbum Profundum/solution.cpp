#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
   public:
    vector<TrieNode*> children;

    TrieNode() {
        children.resize(26);
    }
};

void insert(TrieNode* root, string key) {
    TrieNode* traverse = root;

    // add the key reversly
    for (int i = key.size() - 1; i >= 0; i--) {
        if (traverse->children[key[i] - 'a'] == NULL)
            traverse->children[key[i] - 'a'] = new TrieNode();

        traverse = traverse->children[key[i] - 'a'];
    }
}

bool search(TrieNode* root, string key) {
    TrieNode* traverse = root;

    // search the key until its middle
    for (int i = 0; i < (key.size() + 1) / 2; i++) {
        if (traverse->children[key[i] - 'a'] == NULL)
            return false;

        traverse = traverse->children[key[i] - 'a'];
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TrieNode* root = new TrieNode();

    int n;
    cin >> n;
    vector<string> strList;

    while (n--) {
        string s;
        cin >> s;
        strList.push_back(s);
        insert(root, s);
    }

    int result = 0;
    for (string& str : strList) {
        if (search(root, str))
            result++;
    }

    cout << result << endl;

    return 0;
}
