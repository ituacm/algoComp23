#include <bits/stdc++.h>

using namespace std;

long long parent(long long node, vector<long long>& ancestor) {
    if (ancestor[node] == node)
        return node;
    return ancestor[node] = parent(ancestor[node], ancestor);
}

void make_union(long long node1, long long node2, vector<long long>& ancestor) {
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
    long long node_count, edge_count;
    cin >> node_count >> edge_count;

    vector<vector<long long>> edgeList(edge_count);
    for (long long i = 0; i < edge_count; i++) {
        long long src, dest, cost;
        cin >> src >> dest >> cost;
        edgeList[i] = {cost, src, dest};
    }

    // sort the edge list by cost
    sort(edgeList.begin(), edgeList.end());

    // initalize union find set
    vector<long long> ancestor(node_count);

    // make everybody their own parent
    iota(ancestor.begin(), ancestor.end(), 0);

    // find the mst costs
    vector<long long> mst_results;
    for (auto& edge : edgeList) {
        if (!find(edge[1], edge[2], ancestor)) {
            make_union(edge[1], edge[2], ancestor);
            mst_results.push_back(edge[0]);
        }
    }

    // get the queries
    long long query_count;
    cin >> query_count;
    vector<long long> query_list(query_count);

    for (long long i = 0; i < query_count; i++) {
        cin >> query_list[i];
    }

    // to use in binary search
    sort(mst_results.begin(), mst_results.end());

    // prefix sum for fast summation
    vector<long long> prefix(node_count - 1, 0);

    for (long long i = 0; i < node_count - 1; i++) {
        if (i) {
            prefix[i] = mst_results[i] + prefix[i - 1];
        } else {
            prefix[i] = mst_results[i];
        }
    }

    // print the binary search results
    for (long long i = 0; i < query_count; i++) {
        long long index = upper_bound(mst_results.begin(), mst_results.end(), query_list[i]) - mst_results.begin();
        long long ans = 0;
        if (index) ans += prefix[index - 1];
        ans += (node_count - 1 - index) * query_list[i];
        cout << ans << "\n";
    }

    return 0;
}
