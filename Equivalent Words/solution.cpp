#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define ALPHABET_SIZE 26

string calculateHashString(string word) {
    vector<int> alphabet(ALPHABET_SIZE);
    for (char ch : word) {
        alphabet[tolower(ch) - 'a']++;
    }

    vector<int> letterCounts;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (alphabet[i] > 0)
            letterCounts.push_back(alphabet[i]);
    }

    sort(letterCounts.begin(), letterCounts.end());

    string hashString;
    for (int count : letterCounts) {
        hashString += to_string(count);
        hashString += ',';
    }
    return hashString;
}

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, vector<int>> acronyms;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        acronyms[calculateHashString(word)].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;
        printVector(acronyms[calculateHashString(query)]);
    }

    return 0;
}
