#include <bits/stdc++.h>

using namespace std;


int dfs(vector<vector<int>>& adjList, vector<int>& depths, int node, int parent ){

    // leaves
    if (adjList[node].size() == 1 && adjList[node][0] == parent){
        return depths[node] = 0;
    }

    vector<int> child_depths;
    for (int next_node: adjList[node]){
        if (next_node != parent)
            child_depths.push_back(dfs(adjList, depths, next_node, node));
    }

    int max_depth = 0;
    sort(child_depths.begin(), child_depths.end(), greater<int>());
    for (int i = 0; i < child_depths.size(); i++){
        max_depth = max(max_depth, child_depths[i] + i + 1);
    }

    return depths[node] = max_depth;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adjList(n+1);

    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int root;
    cin >> root;

    vector<int> depths(n+1);

    cout << dfs(adjList, depths, root, -1);

    return 0;
}
