#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes;
    vector<bool> sieve(1299710, false);
    for (LL i = 2; i < sieve.size(); i++) {
        if (sieve[i]) continue;

        primes.push_back(i);

        for (LL k = i*i; k < sieve.size(); k += i)  sieve[k] = true; 
    }

    int tc;
    cin >> tc;



    while (tc--) {
        int n;
        cin >> n;

        if (!sieve[n]) {
            cout << 0 << '\n';
        }
        else {
            auto it = lower_bound(primes.begin(), primes.end(), n);
            auto preIt = it;
            preIt--;
            
            cout << *it - *preIt  << '\n';
        }
    }
    return 0;
}