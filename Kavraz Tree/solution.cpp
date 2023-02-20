#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& adjList, vector<int>& kavrazLevels, int node, int parent) {
    // leaves
    if (adjList[node].size() == 1 && adjList[node][0] == parent) {
        return kavrazLevels[node] = 0;
    }

    // for internal nodes, find the kavraz levels of all nodes in subtree
    vector<int> childKavrazLevels;
    for (int next_node : adjList[node]) {
        if (next_node != parent)
            childKavrazLevels.push_back(dfs(adjList, kavrazLevels, next_node, node));
    }

    sort(childKavrazLevels.begin(), childKavrazLevels.end(), greater<int>());
    int maxDepth = 0;
    for (int i = 0; i < childKavrazLevels.size(); i++) {
        maxDepth = max(maxDepth, childKavrazLevels[i] + i + 1);
    }

    return kavrazLevels[node] = maxDepth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adjList(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int root;
    cin >> root;

    vector<int> kavrazLevels(n + 1);

    cout << dfs(adjList, kavrazLevels, root, -1);

    return 0;
}
