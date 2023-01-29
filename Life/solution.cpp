#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MOD (1000000007)

using namespace std;

class SegmentTree {
    vector<long long> tree;

public:
    SegmentTree(long long n){
        tree.resize(n*4 + 5);
    }

    void build(long long ind, long long l, long long r, vector<long long>& nums){

        if (l > r)
            return;

        if (l == r)
            this->tree[ind] = nums[l];

        else {
            long long mid = (l+r) / 2;
            build(ind * 2, l, mid, nums);
            build(ind * 2 + 1, mid + 1, r, nums);

            tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
        }
    }

    void update(long long ind, long long l, long long r, long long x, long long val){

        if (l > r)
            return;

        if (l > x || r < x)
            return;
        if (l == x && r == x){
            this->tree[ind] += val;
            // cout << "Update: " << this->tree[ind] << "\n";
            return;
        }

        long long mid = (l + r) / 2;

        update(ind * 2, l, mid, x, val);
        update(ind * 2 + 1, mid + 1, r, x, val);
        this->tree[ind] = this->tree[ind * 2] + this->tree[ind * 2 + 1];
    }

    long long query(long long ind, long long l, long long r, long long target_l, long long target_r){


        if (target_r < l || r < target_l)
            return 0;

        if (target_l <= l && r <= target_r)
            return this->tree[ind];

        long long mid = (l + r) / 2;
        return query(ind * 2, l, mid, target_l, target_r) +
            query(ind * 2 + 1, mid + 1, r, target_l, target_r);
    }

    void printTree(long long size){
        for (long long i = 1; i <= size * 2; i++)
            cout << tree[i] << " ";
        cout << "\n";
    }
};

void printVector(vector<long long>& v){
    for (long long itr: v){
        cout << itr << " ";
    } cout << "\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m, k;
    cin >> n >> m >> k;
        
    // read the input long longo a vector
    vector<long long> happinessScores(n);
    for (long long i = 0; i < n; i++){
        cin >> happinessScores[i];
    }

    vector<SegmentTree*> segmentTrees(k);
    
    for (long long i = 0; i < k; i++){
        segmentTrees[i] = new SegmentTree(n / k);
    }

    vector<vector<long long>> separatedNumbers(k);
    long long prefix_sum = 0;
    for (long long i = 0; i < k; i++){
        prefix_sum += happinessScores[i];
    }

    for (long long i = k; i < n; i++){
        long long effect = (i / k) % 2 == 1 ? 1 : -1;
        separatedNumbers[(i - k) % k].push_back(effect * prefix_sum);
        prefix_sum += happinessScores[i] - happinessScores[i - k];
    }

    long long effect = (n / k) % 2 == 1 ? 1 : -1;
    separatedNumbers[(n - k) % k].push_back(effect * prefix_sum);

    for (long long i = 0; i < k; i++){
        segmentTrees[i]->build(1, 0, separatedNumbers[i].size() - 1, separatedNumbers[i]);
    }

    for (long long i = 0; i < m; i++){

        // update operation
        long long qType; cin >> qType; 
        if (qType == 1){
            long long index, new_value;
            cin >> index >> new_value;
            
            // update array at first
            long long diff = new_value - happinessScores[index];
            happinessScores[index] = new_value;

            for (long long j = 0; j < k; j++){
                if (index >= j){
                    long long updateIndex = (index - j) / k;
                    long long effect = (index - j) % (2 * k) >= k ? -1 : 1;
                    if (updateIndex < separatedNumbers[j].size()){
                        segmentTrees[j]->update(1, 0, separatedNumbers[j].size() - 1, updateIndex, effect * diff);
                    }
                }
            }

        }
        else if (qType == 2) {

            long long l, r; cin >> l >> r;

            // instead of l, l-1 and instead of r, r-1 for the segment tree operations 
            // for example the calculation of remainingSum doesn't change except mod part
            long long new_l = (l - (l % k)) / k;
            long long new_r = (r - ((r - (l % k)) % k)) / k - 1;

            long long remainingSum = 0;
            for (long long j = r - ((r - (l % k)) % k); j <= r; j++)
                remainingSum += happinessScores[j];
            
            if (((r - l) / k) % 2 == 1)
                remainingSum = -remainingSum;
            
            long long querySum = segmentTrees[l % k]->query(1, 0, separatedNumbers[l % k].size() - 1, new_l, new_r);
            
            if (new_l % 2 == 1)
                querySum = -querySum;

            cout << (((remainingSum + querySum) % MOD) + MOD) % MOD << "\n";

        }
        else {
            cerr << "Hoooop! Error var hoca!";
            return 1;
        }
    }
}
