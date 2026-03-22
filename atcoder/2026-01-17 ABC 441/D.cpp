#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int n, m, l, s, t;
TwoVector<iipair> graph(200100);

void dfs(int cur, vector<int>& chk, int cost = 0, int lv = 0) {
    if (lv == l) {
        chk[cur] |= s <= cost && cost <= t;

        return;
    }

    for (auto& [next, c] : graph[cur]) {
        dfs(next, chk, cost + c, lv + 1 );
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    cin >> n >> m >> l >> s >> t;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        graph[u].push_back({v, c});
    }

    vector<int> chk(n+1, 0);
    dfs(1, chk);

    for (int i = 1; i <= n; i++) {
        if (!chk[i]) continue;

        cout << i << ' ';
    }

    return 0;
}

/*
다음 조건을 만족하는 모든 v를 찾아라


1에서 v로 가는 경로가 존재한다. 다음 조건을 만족하면서
- 정확히 L개의 간선을 지난다. 
- 비용은 최소 S이고 최대 T여야 한다.

비용의 최소도 맞춰야 하니 최단거리 찾는 알고리즘은 이용 못 하겠는데?

근데 플로이드 워셜이나, 벨만 포드 같은 느낌으로 풀긴 해야 하지 않을까?

L이 해봤자 10이네?

4^10 하면 1백만이고
그냥 dfs로 조져?

그걸 n번 해야하니깐 안 되는구나.

1에서 l번 움직여서 갈 수 있는 경로의 개수가 최대 1백만개잖아?

그럼 그거 
*/