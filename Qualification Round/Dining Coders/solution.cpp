#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

class Table {
    unordered_map<int, int> who_has_what;
    priority_queue<pair<int, int>> biggest;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> smallest;
    int center;

public:
    Table(int center, vector<int>& arr){
        this->center = center;

        for (int i = 0; i < arr.size(); i++){
            who_has_what[i] = arr[i];
            smallest.push({arr[i], i});
            biggest.push({arr[i], -i});
        }
    }

    pair<int, int> push_to_center(int new_element){

        while (who_has_what[smallest.top().second] != smallest.top().first){
            smallest.pop();
        }

        auto top = smallest.top(); smallest.pop();

        who_has_what[top.second] = this->center;
        smallest.push({this->center, top.second});
        biggest.push({this->center, -top.second}); // TODO: correct second element

        this->center = new_element;

        return {top.first, top.second + 1};
    }

    int pop_from_center(int new_element){

        while (who_has_what[-biggest.top().second] != biggest.top().first){
            biggest.pop();
        }

        auto top = biggest.top(); biggest.pop();
        
        int previous_center_val = this->center;
        this->center = top.first;

        who_has_what[-top.second] = new_element;
        smallest.push({new_element, -top.second});
        biggest.push({new_element, top.second});
        
        return previous_center_val;
    }

};

int main(int argc, char** argv){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, center;
    cin >> n >> m >> center;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    Table table = Table(center, arr);

    for (int i = 0; i < m; i++){
        int q_type, new_element;
        cin >> q_type >> new_element;

        if (q_type == 1){
            auto ret_val = table.push_to_center(new_element);
            cout << ret_val.first << " " << ret_val.second << "\n";
        } 
        else if (q_type == 2){
            cout << table.pop_from_center(new_element) << "\n";
        } 
        else {
            cerr << "Hatali islem!\n";
        }
    }

    return 0;
}