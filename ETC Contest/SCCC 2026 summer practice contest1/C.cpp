#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL, LL>;

LL cap[1000][1000], flow[1000][1000];
vector<iipair> graph(1000);



int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, c;

        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
        cap[u][v] = c;
    }

    int st = 0, goal = n-1;
    while (true) {
        vector<int> prev(n, -1);
        vector<bool> chk(n, false);
        LL f = 0;

        queue<int> que;
        que.push(st);
        prev[st] = 0;
        chk[st] = true;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            for (auto& [nxt, _] : graph[cur]) {
                LL residual = cap[cur][nxt] - flow[cur][nxt]
                if (chk[nxt] || residual == 0) continue;

                chk[nxt] = true;
                f = min(f, residual);
                que.push(nxt);
                prev[nxt] = cur;
            }
        }

        if (prev[n-1] == -1) break;
        for (int i = n-1; prev[i] != -1; i = prev[i]) {
            flow[prev[i]][i] += f;
            flow[i][prev[i]] += -f;
        }
    }

    return 0;
}