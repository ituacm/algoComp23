#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

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

long long calculateDistanceAllNodePairs(unordered_map<long long, unordered_map<long long, long long>>& adjlist, long long node, long long parent, long long& summationOfDistances, unordered_map<long long, unordered_map<long long, long long>>& howManyTimesUsed, long long totalNodeCount) {
    long long subtreeNodeCount = 0;
    for (auto edge : adjlist[node]) {
        if (edge.first != parent) {
            subtreeNodeCount += calculateDistanceAllNodePairs(
                adjlist,
                edge.first,
                node,
                summationOfDistances,
                howManyTimesUsed,
                totalNodeCount);
        }
    }
    subtreeNodeCount += 1;

    if (parent != -1) {
        long long how_many_times_used = (subtreeNodeCount) * (totalNodeCount - subtreeNodeCount);
        summationOfDistances += how_many_times_used * adjlist[node][parent];
        howManyTimesUsed[node][parent] = how_many_times_used;
        howManyTimesUsed[parent][node] = how_many_times_used;
    }

    return subtreeNodeCount;
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
    vector<vector<long long>> mstResults;
    for (auto& edge : edgeList) {
        if (!find(edge[1], edge[2], ancestor)) {
            makeUnion(edge[1], edge[2], ancestor);
            mstResults.push_back({edge[0], edge[1], edge[2]});
        }
    }

    sort(mstResults.begin(), mstResults.end());

    // assign id's to the edges to find them quickly later.
    unordered_map<long long, unordered_map<long long, long long>> mstAdjList;
    // holds the number of usage between all node pairs for each edge
    unordered_map<long long, unordered_map<long long, long long>> howManyTimesUsed;

    for (auto mstResult : mstResults) {
        long long cost = mstResult[0];
        long long adj1 = mstResult[1];
        long long adj2 = mstResult[2];
        mstAdjList[adj1][adj2] = cost;
        mstAdjList[adj2][adj1] = cost;
    }

    long long summationOfDistances = 0;  // summation of distances between all node pairs
    calculateDistanceAllNodePairs(mstAdjList, 0, -1, summationOfDistances, howManyTimesUsed, nodeCount);

    // get the queries
    long long queryCount;
    cin >> queryCount;

    // for every query
    for (long long i = 0; i < queryCount; i++) {
        long long query;
        cin >> query;

        // find the maximum effect on cost, at least it should be 0.
        long long maxDecreaseInCost = 0;

        // look up to the all edges
        for (auto mstResult : mstResults) {
            long long edgeCost = mstResult[0];
            long long adj1 = mstResult[1];
            long long adj2 = mstResult[2];

            // calculate the value and check the max
            long long decreaseInCost = (edgeCost - query) * howManyTimesUsed[adj1][adj2];
            maxDecreaseInCost = max(maxDecreaseInCost, decreaseInCost);
        }

        // print the result
        cout << summationOfDistances - maxDecreaseInCost << "\n";
    }

    return 0;
}