#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> prime(100100, 0);
    prime[1] = 1;
    for (LL i = 2; i < 100100; i++) {
        if (prime[i]) continue;
        prime[i] = i;

        for (LL k = i; k < 100100; k += i) {
            prime[k] = i;
        }
    }

    int n, k;
    cin >> n >> k;


    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += prime[i] <= k;
    }

    cout << ans;
    return 0;
}
