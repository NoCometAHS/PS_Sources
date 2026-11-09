#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

struct Range{
    int len;
    int st;
    int en;

    Range(int l = -1, int s = -1, int e = -1) : len(l), st(s), en(e) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    vector<Range> ranges;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int k = i; k < n; k++) {
            sum += arr[k];

            if (i == 0 and k == n-1) continue;
            ranges.emplace_back(sum, i+1, k+1);
        }
    }

    int ans = 1e9;
    constexpr int inf = 0x3f3f3f3f;
    int dp[55];

    for (const auto& mn : ranges) {
        memset(dp, 0x3f, sizeof(dp));

        dp[0] = 0;
        for (int i = 0; i < 50; i++) {
            for (auto [len, st, en] : ranges) {
                if (len < mn.len) continue;
                if (dp[st-1] == inf) continue;

                dp[en] = min(dp[en], max(dp[st-1], len));
            }
        }


        if (dp[n] != inf) {
            ans = min(ans, dp[n] - mn.len);
        }
    }

    cout << ans;

    return 0;
}