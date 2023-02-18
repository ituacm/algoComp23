#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<int>& primes) {
    if (primes[0] + primes[1] + primes[2] < 36)
        return false;
    if (primes[0] + primes[1] < 10 || primes[1] + primes[2] < 21 || primes[0] + primes[2] < 21)
        return false;
    if (primes[0] < 3 || primes[1] < 3 || primes[2] < 10)
        return false;
    return true;
}

int findResult(vector<int>& primes) {
    return primes[0] + 2 * primes[1] + primes[2];
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int num;
        cin >> num;

        // used unoptimized prime finding, it can optimize with using sieve
        vector<int> primes;
        int xx = num;
        int c = 2;
        while (num > 1) {
            if (num % c == 0) {
                primes.push_back(c);
                num /= c;
            } else
                c++;
        }

        sort(primes.begin(), primes.end());

        set<int> result;
        do {
            if (isValid(primes)) {
                result.insert(findResult(primes));
            }
        } while (next_permutation(primes.begin(), primes.end()));

        if (result.size() == 0) {
            cout << -1 << "\n";
            continue;
        }

        for (auto itr = result.begin(); itr != result.end(); itr++) {
            cout << *itr << " ";
        }
        cout << "\n";
    }

    return 0;
}