#include <bits/stdc++.h>

using namespace std;

long long parent(long long node, vector<long long>& ancestor) {
    if (ancestor[node] == node)
        return node;
    return ancestor[node] = parent(ancestor[node], ancestor);
}

void makeUnion(long long node1, long long node2, vector<long long>& ancestor) {
    long long p1 = parent(node1, ancestor);
    long long p2 = parent(node2, ancestor);
    ancestor[p1] = p2;
}

bool find(long long node1, long long node2, vector<long long>& ancestor) {
    return parent(node1, ancestor) == parent(node2, ancestor);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // get input to a edge list
    long long nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    vector<vector<long long>> edgeList(edgeCount);
    for (long long i = 0; i < edgeCount; i++) {
        long long src, dest, cost;
        cin >> src >> dest >> cost;
        edgeList[i] = {cost, src, dest};
    }

    // sort the edge list by cost
    sort(edgeList.begin(), edgeList.end());

    // initalize union find set
    vector<long long> ancestor(nodeCount);

    // make everybody their own parent
    iota(ancestor.begin(), ancestor.end(), 0);

    // find the mst costs
    vector<long long> mstResults;
    for (auto& edge : edgeList) {
        if (!find(edge[1], edge[2], ancestor)) {
            makeUnion(edge[1], edge[2], ancestor);
            mstResults.push_back(edge[0]);
        }
    }

    // get the queries
    long long queryCount;
    cin >> queryCount;
    vector<long long> queryList(queryCount);

    for (long long i = 0; i < queryCount; i++) {
        cin >> queryList[i];
    }

    // to use in binary search
    sort(mstResults.begin(), mstResults.end());

    // prefix sum for fast summation
    vector<long long> prefix(nodeCount - 1, 0);

    for (long long i = 0; i < nodeCount - 1; i++) {
        if (i) {
            prefix[i] = mstResults[i] + prefix[i - 1];
        } else {
            prefix[i] = mstResults[i];
        }
    }

    // print the binary search results
    for (long long i = 0; i < queryCount; i++) {
        long long index = upper_bound(mstResults.begin(), mstResults.end(), queryList[i]) - mstResults.begin();
        long long ans = 0;
        if (index) ans += prefix[index - 1];
        ans += (nodeCount - 1 - index) * queryList[i];
        cout << ans << "\n";
    }

    return 0;
}
