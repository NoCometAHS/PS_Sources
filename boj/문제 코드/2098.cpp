#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (auto& v : graph) {
        for (auto& i : v) cin >> i;
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, 1e9));
    dp[1][0] = 0;

    for (int s = 1; s < (1 << n); s++) {
        for (int cur = 0; cur < n; cur++) {
            if (~s & (1 << cur)) continue;

            int preState = s & ~(1 << cur);

            for (int pre = 0; pre < n; pre++) {
                if (~preState & (1 << pre)) continue;
                if (graph[pre][cur] == 0) continue;

                dp[s][cur] = min(dp[s][cur], dp[preState][pre] + graph[pre][cur]);
            }
        }
    }

    int ans = 1e9;
    for (int i = 1; i < n; i++) {
        if (!graph[i][0]) continue;
        ans = min(ans, dp[(1 << n) - 1][i] + graph[i][0]);
    }
    cout << ans;

    return 0;
}

/*
dp[방문한 곳][지금 도착한 곳]
dp[s][v] = min(dp[u & ~(1 << v)][u] + u에서 v로 가는 비용)

어디서 출발하는지가 없구나.
마지막에서 출발하는 점으로 돌아 오는 게 없네.
*/