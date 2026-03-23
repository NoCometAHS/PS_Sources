#include "bits/stdc++.h"

using namespace std;
using LL = long long;

int dfs(int cur, int pre, int curDepth, vector<vector<int>>& graph, vector<int>& depth) {
    if (depth[cur]) {
        return curDepth - depth[cur];
    }

    depth[cur] = curDepth;

    for (auto& next : graph[cur]) {
        if (next == pre) continue;

        int ret = dfs(next, cur, curDepth+1, graph, depth);
        if (ret) return ret;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    
    vector<int> depth(n+1, 0);

    if (dfs(1, -1, 1, graph, depth) % 2) cout << 3;
    else cout << 2;

    

    return 0;
}

/*
트리에 간선하나 추가한 모양의 그래프

트리에서는 2가지 색만 있으면 가능함.

하나가 추가되면서 3개가 필요할 것 같은데, 2개일 때도 있어.

4개가 필요한 경우는?
지도를 3가지 색으로 칠할 수 있다고 하지 않나. 4색이네 ㅋㅋ.

그렇다면
답은 2 ~ 4 겠다.

사이클은 무조건 1개만 존재한다.
사이클 외의 노드들은 2가지 색이면 충분함. 다 트리니깐

따라서 색의 종류는 사이클에 따라 달라지는데,
홀수 사이클이 있으면 무조건 3색이 필요해.
짝수 사이클은 2개면 됨.

사이클 크기 구하면 되겠다.
*/
