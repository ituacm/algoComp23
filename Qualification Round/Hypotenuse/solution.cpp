#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7+5;

bitset<maxN> isPrime;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l, r; cin >> l >> r;

    
    int ans = 0;
    for (int i = l; i <=r ; i++) {
        if (!isPrime[i] && i%4 == 1) {
            ans++;
        }
    }

    cout << ans;
}

int main() {
    isPrime[1] = 1;
    for (int i = 2; i*i < maxN; i++) {
        if (isPrime[i] == 0) {
            for (int j = i*i; j < maxN; j+=i) {
                isPrime[j] = 1;
            }
        }
    }
    solve();
}
