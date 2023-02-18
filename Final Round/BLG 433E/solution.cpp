#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
const int MAX_VAL = 1000000 + 1;

// n -> number of data streams
// initialize -> O(n * log n)
// each query -> O(log n * log n)

class orderStatsTree{
    vector<unsigned int> BIT;
public:
    int size;
    orderStatsTree(){
        this->BIT = vector<unsigned int>(MAX_VAL, 0);
        this->size = 0;
    }
    void insert(int val);
    void remove(int val);
    int find(int k);
    void update(int index, int add);
    int sum(int index);
};

void orderStatsTree::update(int index, int add){
    while (index > 0 && index < this->BIT.size()){
        this->BIT[index] += add;
        index = index + (index & (-index));
    }
}

void orderStatsTree::insert(int val){
    update(val, 1);
    this->size++;
}

void orderStatsTree::remove(int val){
    update(val, -1);
    this->size--;
}

int orderStatsTree::find(int k){
    int l = 0;
    int h = BIT.size();

    // search for the kth biggest element
    k = this->size - k + 1;

    while (l < h){
        int mid = (l + h) / 2;
        if (k <= sum(mid))
            h = mid;
        else
            l = mid+1;
    }

    return l;
}

int orderStatsTree::sum(int index){
    int sum = 0;
    while (index > 0){
        sum += this->BIT[index];
        index = index - (index & (-index));
    }
    return sum;
}

int main(){
    int n, k, q;
    cin >> n >> k >> q;

    vector<queue<int>> streams(n);
    orderStatsTree* tree = new orderStatsTree();
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> data_to_stream;

    for (int a = 0; a < n; a++){
        int stream_size;
        cin >> stream_size;
        for (int b = 0; b < stream_size; b++){
            int val;
            cin >> val;
            streams[a].push(val);
        }
    }

    for (int a=0; a<n; a++){
        int val = streams[a].front();
        streams[a].pop();
        tree->insert(val);
        data_to_stream[val].push(a);
    }

    for (int a = 0; a < q; a++) {
        int router;
        cin >> router;

        if (tree->size == 0) {
            cout << -1 << "\n";
            continue;
        }

        if (router > tree->size) {
            router = tree->size;
        }

        int res = tree->find(router);
        tree->remove(res);

        int stream = data_to_stream[res].top();
        data_to_stream[res].pop();

        if (!streams[stream].empty()) {
            int val = streams[stream].front();
            streams[stream].pop();
            tree->insert(val);
            data_to_stream[val].push(stream);
        }

        cout << res << "\n";
    }

    return 0;
}