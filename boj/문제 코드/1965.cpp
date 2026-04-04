#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    vector<int> dp(n, 0);
    dp[0] = 1;

    int ans = 1;
    for (int i = 1; i < n; i++) {
        int mx = 0;
        for (int k = 0; k < i; k++) {
            if (arr[k] >= arr[i]) continue;

            mx = max(mx, dp[k]);
        }

        ans = max(ans, dp[i] = mx + 1);
    }

    cout << ans;
    return 0;
}

