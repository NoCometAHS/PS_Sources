#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    
    TwoVector<LL> arr(n, vector<LL>(2));
    for (auto& v: arr) cin >> v[0] >> v[1];

    LL dp[2200][2], next[2200][2];
    memset(dp, 0x3f, sizeof(dp));
    memset(next, 0x3f, sizeof(next));


    dp[1000][0] = abs(arr[0][0]);
    dp[1000][1] = abs(arr[0][1]);

    for (int i = 1; i < n; i++) {
        for (int k = 0; k <= 2000; k++) {
            next[k][0] = min(next[k][0], dp[k][0] + abs(arr[i][0] - arr[i-1][0]));
            next[arr[i-1][0] + 1000][1] = min(next[arr[i-1][0] + 1000][1], dp[k][0] + abs(k-1000 - arr[i][1]));

            next[arr[i-1][1] + 1000][0] = min(next[arr[i-1][1] + 1000][0], dp[k][1] + abs(k-1000 - arr[i][0]));
            next[k][1] = min(next[k][1], dp[k][1] + abs(arr[i-1][1] - arr[i][1]));
        }

        swap(dp, next);
        memset(next, 0x3f, sizeof(next));
    }

    LL ans = 1e9;
    for (auto& v : dp) for (auto& i : v) ans = min(ans, i);
    cout << ans;

    return 0;
}