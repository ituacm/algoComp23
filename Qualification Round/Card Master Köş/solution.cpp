#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    if (n == 1 && k == 1)
        cout << 0 << endl;
    else if (k == 1)
        cout << -1 << endl;
    else
        cout << ceil(log2(n) / log2(k)) << endl;

    return 0;
}
