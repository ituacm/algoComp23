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

void make_union(long long node1, long long node2, vector<long long>& ancestor) {
    long long p1 = parent(node1, ancestor);
    long long p2 = parent(node2, ancestor);
    ancestor[p1] = p2;
}

bool find(long long node1, long long node2, vector<long long>& ancestor) {
    return parent(node1, ancestor) == parent(node2, ancestor);
}

long long calculate_distance_all_node_pairs(unordered_map<long long, unordered_map<long long, long long>>& adjlist, long long node, long long parent, long long& summation_of_distances_between_all_node_pairs, unordered_map<long long, unordered_map<long long, long long>>& how_many_times_edge_used, long long total_node_count) {
    long long subtree_node_count = 0;
    for (auto edge : adjlist[node]) {
        if (edge.first != parent) {
            subtree_node_count += calculate_distance_all_node_pairs(
                adjlist,
                edge.first,
                node,
                summation_of_distances_between_all_node_pairs,
                how_many_times_edge_used,
                total_node_count);
        }
    }
    subtree_node_count += 1;

    if (parent != -1) {
        long long how_many_times_used = (subtree_node_count) * (total_node_count - subtree_node_count);
        summation_of_distances_between_all_node_pairs += how_many_times_used * adjlist[node][parent];
        how_many_times_edge_used[node][parent] = how_many_times_used;
        how_many_times_edge_used[parent][node] = how_many_times_used;
    }

    return subtree_node_count;
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
    vector<vector<long long>> mst_results;
    for (auto& edge : edgeList) {
        if (!find(edge[1], edge[2], ancestor)) {
            make_union(edge[1], edge[2], ancestor);
            mst_results.push_back({edge[0], edge[1], edge[2]});
        }
    }

    sort(mst_results.begin(), mst_results.end());

    // assign id's to the edges to find them quickly later.
    unordered_map<long long, unordered_map<long long, long long>> mst_adjlist;
    unordered_map<long long, unordered_map<long long, long long>> how_many_times_edge_used;

    for (auto mst_result : mst_results) {
        long long cost = mst_result[0];
        long long adj1 = mst_result[1];
        long long adj2 = mst_result[2];
        mst_adjlist[adj1][adj2] = cost;
        mst_adjlist[adj2][adj1] = cost;
    }

    long long summation_of_distances_between_all_node_pairs = 0;
    calculate_distance_all_node_pairs(mst_adjlist, 0, -1, summation_of_distances_between_all_node_pairs, how_many_times_edge_used, node_count);
    // printf("summation_of_distances_between_all_node_pairs = %lli\n", summation_of_distances_between_all_node_pairs);
    // get the queries
    long long query_count;
    cin >> query_count;

    // for every query
    for (long long i = 0; i < query_count; i++) {
        long long query;
        cin >> query;

        // find the maximum effect on cost, at least it should be 0.
        long long max_decrease_in_cost = 0;

        // look up to the all edges
        for (auto mst_result : mst_results) {
            long long edge_cost = mst_result[0];
            long long adj1 = mst_result[1];
            long long adj2 = mst_result[2];

            // calculate the value and check the max
            // printf("Edge_Cost = %lli, Times = %lli\n", edge_cost, how_many_times_edge_used[adj1][adj2]);
            long long decrease_in_cost = (edge_cost - query) * how_many_times_edge_used[adj1][adj2];
            max_decrease_in_cost = max(max_decrease_in_cost, decrease_in_cost);
        }
        // printf("Max Decrease = %lli\n", max_decrease_in_cost);

        // print the result
        cout << summation_of_distances_between_all_node_pairs - max_decrease_in_cost << "\n";
    }

    return 0;
}