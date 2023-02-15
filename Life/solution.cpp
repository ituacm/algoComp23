#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

#define MOD (1000000007)

using namespace std;

class SegmentTree {
    vector<long long> tree;

   public:
    SegmentTree(long long n) {
        tree.resize(n * 4 + 5);
    }

    void build(long long ind, long long l, long long r, vector<long long>& nums) {
        if (l > r) return;

        if (l == r) {
            this->tree[ind] = nums[l];
        } else {
            long long mid = (l + r) / 2;
            build(ind * 2, l, mid, nums);
            build(ind * 2 + 1, mid + 1, r, nums);

            tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
        }
    }

    void update(long long ind, long long l, long long r, long long x, long long val) {
        if (l > r) return;

        if (l > x || r < x) return;

        if (l == x && r == x) {
            this->tree[ind] += val;
            return;
        }

        long long mid = (l + r) / 2;

        update(ind * 2, l, mid, x, val);
        update(ind * 2 + 1, mid + 1, r, x, val);
        this->tree[ind] = this->tree[ind * 2] + this->tree[ind * 2 + 1];
    }

    long long query(long long ind, long long l, long long r, long long target_l, long long target_r) {
        if (target_r < l || r < target_l)
            return 0;

        if (target_l <= l && r <= target_r)
            return this->tree[ind];

        long long mid = (l + r) / 2;
        return query(ind * 2, l, mid, target_l, target_r) +
               query(ind * 2 + 1, mid + 1, r, target_l, target_r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k;
    cin >> n >> m >> k;

    // read the input long long a vector
    vector<long long> happinessScores(n);
    for (long long i = 0; i < n; i++) {
        cin >> happinessScores[i];
    }

    vector<SegmentTree*> segmentTrees(k);

    for (long long i = 0; i < k; i++) {
        segmentTrees[i] = new SegmentTree(n / k);
    }

    vector<vector<long long>> separatedNumbers(k);
    long long prefixSum = 0;
    for (long long i = 0; i < k; i++) {
        prefixSum += happinessScores[i];
    }

    for (long long i = k; i < n; i++) {
        long long effect = (i / k) % 2 == 1 ? 1 : -1;
        separatedNumbers[(i - k) % k].push_back(effect * prefixSum);
        prefixSum += happinessScores[i] - happinessScores[i - k];
    }

    long long effect = (n / k) % 2 == 1 ? 1 : -1;
    separatedNumbers[(n - k) % k].push_back(effect * prefixSum);

    for (long long i = 0; i < k; i++) {
        segmentTrees[i]->build(1, 0, separatedNumbers[i].size() - 1, separatedNumbers[i]);
    }

    for (long long i = 0; i < m; i++) {
        long long qType;
        cin >> qType;
        if (qType == 1) {
            long long index, newValue;
            cin >> index >> newValue;

            // update array at first
            long long diff = newValue - happinessScores[index];
            happinessScores[index] = newValue;

            for (long long j = 0; j < k; j++) {
                if (index >= j) {
                    long long updateIndex = (index - j) / k;
                    long long effect = (index - j) % (2 * k) >= k ? -1 : 1;
                    if (updateIndex < separatedNumbers[j].size()) {
                        segmentTrees[j]->update(1, 0, separatedNumbers[j].size() - 1, updateIndex, effect * diff);
                    }
                }
            }
        } else {
            long long l, r;
            cin >> l >> r;

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
    }
    return 0;
}
