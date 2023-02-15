#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Table {
    unordered_map<int, int> whoHasWhat;
    priority_queue<pair<int, int>> biggest;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> smallest;
    int center;

   public:
    Table(int center, vector<int>& arr) {
        this->center = center;

        for (int i = 0; i < arr.size(); i++) {
            whoHasWhat[i] = arr[i];
            smallest.push({arr[i], i});
            biggest.push({arr[i], -i});
        }
    }

    pair<int, int> pushToCenter(int newElement) {
        while (whoHasWhat[smallest.top().second] != smallest.top().first) {
            smallest.pop();
        }

        auto top = smallest.top();
        smallest.pop();

        whoHasWhat[top.second] = this->center;
        smallest.push({this->center, top.second});
        biggest.push({this->center, -top.second});  // TODO: correct second element

        this->center = newElement;

        return {top.first, top.second + 1};
    }

    int pop_from_center(int newElement) {
        while (whoHasWhat[-biggest.top().second] != biggest.top().first) {
            biggest.pop();
        }

        auto top = biggest.top();
        biggest.pop();

        int previousCenterValue = this->center;
        this->center = top.first;

        whoHasWhat[-top.second] = newElement;
        smallest.push({newElement, -top.second});
        biggest.push({newElement, top.second});

        return previousCenterValue;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, center;
    cin >> n >> m >> center;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Table table = Table(center, arr);

    for (int i = 0; i < m; i++) {
        int q_type, newElement;
        cin >> q_type >> newElement;

        if (q_type == 1) {
            auto ret_val = table.pushToCenter(newElement);
            cout << ret_val.first << " " << ret_val.second << "\n";
        } else {
            cout << table.pop_from_center(newElement) << "\n";
        }
    }

    return 0;
}