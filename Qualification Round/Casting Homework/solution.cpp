#include <bits/stdc++.h>
using namespace std;

const int maxk = 20;

string solve(string s, int target, int k) {
    int n = s.size();

    vector<bool> found(k + 1, false);

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = s[i] - 'a' + 1;

    bitset<maxk> bs;
    int upperbound = 1 << n;

    for (int i = 1; i < upperbound; i++) {
        bs = bitset<maxk>(i);
        if (bs.count() > k)
            continue;

        if (found[bs.count()])
            continue;

        int sum = 0;
        for (int j = 0; j < n; j++)
            if (bs.test(j))
                sum += nums[j];
        if (sum == target) {
            found[bs.count()] = true;
        }
    }
    string res = "";
    for (int i = 1; i <= k; i++)
        res = res + to_string(found[i]) + " ";

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int targetSum, kmax;
    string st;

    cin >> st;
    cin >> targetSum >> kmax;

    string res = solve(st, targetSum, kmax);
    cout << res;

    return 0;
}
