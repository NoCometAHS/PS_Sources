#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;


graphT graph(500);
vector<int> dist(500);

int GetMinCycle(int cur) {
    queue<iipair> que;
    que.emplace(cur, -1);
    dist[cur] = 0;

    int ret = 1e9;
    while (!que.empty()) {
        auto [cur, pre] = que.front();
        que.pop();

        for (auto& next : graph[cur]) {
            if (dist[next] != 1e9) {
                if (next != pre) {
                    ret = min(ret,dist[cur] + dist[next] + 1);
                }
            }
            else {
                dist[next] = dist[cur] + 1;

                que.emplace(next, cur);
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    for (int tt = 1; tt <= tc; tt++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            fill(dist.begin(), dist.end(), 1e9);
            ans = min(ans, GetMinCycle(i));
        }

        cout << "Case " << tt << ": ";
        if (ans < 1e9) cout << ans << '\n';
        else cout << "impossible\n";

        for (auto& v : graph) v.clear();
    }

    return 0;
}

// 사이클이면 어디 하나 잘려도 잘 다님
// 갈 수 있는 경로가 2개 이상이다? 무방향 그래프에서는 사이클이지.
// 3개 이상으로 늘릴 필요가 있냐.