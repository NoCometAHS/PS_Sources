#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    vector<int> dp(n, 0);
    dp[0] = arr[0];

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int t = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j])
            t = max(dp[j], t);
        }

        dp[i] = t + arr[i];
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
