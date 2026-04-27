#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sieve(1100100, false);
    sieve[0] = sieve[1] = true;
    for (LL i = 2; i < 1100100; i++) {
        if (sieve[i]) continue;

        for (LL k = i * i; k < 1100100; k += i) {
            sieve[k] = true;
        }
    }

    vector<int> dp(100100, 0);
    for (int i = 1; i < 100100; i++) {
        bool f = !sieve[i+1];

        for (int k = 10; k <= i; k *= 10) {
            LL left = i / k, right = i % k;

            LL res = left * right + 1;

            f &= !sieve[res];
        }

        dp[i] = f;
    }

    for (int i = 1; i < 100100; i++) dp[i] += dp[i-1];

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}

// 걍 메모라이제션? 해도 되는 거 아니냐
// 1000000 까지 소수는 구해두죠