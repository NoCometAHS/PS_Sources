#include "bits/stdc++.h"

using namespace std;
using LL = long long;


using iipair = pair<LL, LL>;

template <typename t>
using TwoVec = vector<vector<t>>;

int n, m, t;

LL func(TwoVec<LL>& monsters, TwoVec<LL>& graph, LL def) {
    TwoVec<LL> dp(t+1, vector<LL>(n, 0));

    LL ret = dp[1][0] = (monsters[0][0] <= monsters[0][2] * def ? monsters[0][3] : 0);
    for (int time = 2; time <= t; time++) {
        for (int curRoom = 0; curRoom < n; curRoom++) {
            LL& curRes = dp[time][curRoom];

            for (auto& preRoom : graph[curRoom]) {
                LL preRes = dp[time-1][preRoom];

                if (preRes == 0) continue;
                if (monsters[curRoom][0] +  monsters[curRoom][1]*(time-1) <= monsters[curRoom][2]*def) {
                    curRes = max(curRes, preRes + monsters[curRoom][3]);
                    ret = max(ret, curRes);
                }
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin >> n >> m >> t;


    TwoVec<LL> monsters(n, vector<LL>(4));
    for (auto& v : monsters) {
        for (auto& i : v) cin >> i;
    }

    TwoVec<LL> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[v].push_back(u);
    }


    LL lt = 0, rt = 2e9, mid;
    LL mxRes = func(monsters, graph, 2e9);
    LL ans;

    while (lt <= rt) {
        mid = (lt + rt) / 2;

        LL res = func(monsters, graph, mid);
        if (res == mxRes) {
            ans = mid;
            rt = mid -1;
        }
        else {
            lt = mid + 1;
        }
    }

    cout << ans;

    return 0;
}

// T번 움직이는 데, 필요한 방어력의 최소값 구하기네.
//
//
// 깊이가 100이면 그냥 dfs 돌려도 되나? 태그 보니깐 안 되나 봄 ㅋㅋ.
// 떨어뜨리는 금화 개수가 있었네 ㅋㅋ.
//
// dp로만 풀어도 되는 거 아니냐
//
/*
돈
dp[t][n] = max(dp[t][n], dp[t-1][v]+monster[3])

방어력


a + xt - yd = 0
yd = xt + a
d = ceil((xt + a)/y)

-틀-
*/