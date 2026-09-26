#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

constexpr LL mod = 998244353;

void dfs(int cur, vector<int>& res, vector<bool>& chk, TwoVector<LL>& graph) {
    chk[cur] = true;

    for (auto& next : graph[cur]) {
        if (chk[next]) continue;

        dfs(next, res, chk, graph);
    }

    res.push_back(cur);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        int n, m;
        cin >> n >> m;
        
        vector<LL> arr(n);
        for (auto& i : arr) cin >> i;
        
        TwoVector<LL> graph(n);
        TwoVector<LL> reverseGraph(n);
        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;

            from--, to--;
            if (arr[from] >= arr[to]) continue;

            graph[from].push_back(to);
            reverseGraph[to].push_back(from);
        }

        vector<int> order;
        vector<bool> chk(n, false);

        for (int i = 0; i < n; i++) {
            if (chk[i]) continue;
            cout << i << ' ';
            dfs(i, order, chk, graph);
        }

        reverse(order.begin(), order.end());
        cout << "- " ;for (int i = 0; i < n; i++) cout << order[i] << ' ';
        cout << '\n';

        vector<LL> dp(n, 0);
        LL ans = 0;
        for (auto& cur : order) {
            dp[cur] += reverseGraph[cur].size();

            for (auto& pre : reverseGraph[cur]) {
                bool flag = false;

                for (auto& prepre : reverseGraph[pre]) {
                    if (arr[pre] + arr[prepre] != arr[cur]) continue;
                    flag = true;
                    break;
                }

                if (flag) dp[cur] +=  dp[pre];
                dp[cur] %= mod;
            }

            ans += dp[cur];
            ans %= mod;
        }

        //cout << ans << '\n';

    }
    return 0;
}

/*
n개의 정점, m개의 간선
유향 그래프

정점에는 양수가 있음.

단순 경로의 숫자 세기. 
하지만 피보나치 규칙을 따르는 경로인?

---
사이클이 없었다면

위상정렬후 dp 했으면 좋았을 것같은데.

!
a -> b
일때
a >= b
이면 그 간선 없애도 되잖아.
가는 길이 더 작거나 같으면 무조건 피보나치 형식을 못 따르니깐

모든 정점에는 수가 적혀 있고, 이런 경우에 위 규칙을 적용하면
사이클은 없어져
a < b < c < a 인 경우는 없으니깐

1(1) -> 2(1) -> 3(2) -> 4(3)
일 때 답은?
1 1
1 2
2 3
1 1 2
1 2 3
1 1 2 3


dp[4] = dp[3] + 1;


----
dp[간선][피보나치 경로의 길이] 로 풀었네.
간선의 정점 합이 큰 순서대로 하는 방식으로.

순서를 알고리즘 적인 위상정렬 생각하는 게 아니라, 그냥 순서를 정하는 게 중요함을 알았더라면 좋았을 텐데. 
*/