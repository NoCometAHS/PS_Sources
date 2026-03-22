#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL n, m;
        cin >> n >> m;
        
        if (n == m) {
            cout << 0 << '\n';
            continue;
        }

        map<LL, LL> dist;
        queue<LL> order;

        order.push(n);
        while (!order.empty()) {
            LL cur = order.front();
            order.pop();

            if (cur == m) break;
            
            if (cur / 2 >= m && !dist.count(cur / 2))  {
                dist[cur / 2] = dist[cur] + 1;
                order.push(cur / 2);
            }

            if (cur % 2 && cur / 2 + 1 >= m && !dist.count(cur / 2 + 1))  {
                dist[cur / 2 + 1] = dist[cur] + 1;
                order.push(cur / 2 + 1);
            }
        }

        if (dist.count(m)) {
            cout << dist[m] << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}

/*
1
2더미로 나누는데 1분

k 사과 먹고 싶음.
정확히 k개 있는 사과 더미.

정확히 k개로 나눌 수 있으면 최소 연산 횟수.

n이 2^a 꼴이라면 계속 나눠 봐서 되는 지 보면 되는 데

홀수가 문제야
n/2 + 1, n/2 둘중 뭘 선택해야 할까.

dfs?
    log_2 n의 깊이
    29
    가능한 것 같기도
    ㄴㄴ 시간 초과




반대로 생각해볼까?
k가 n이 돼야 해

*2와 *2 + 1 어떻게 쓰던
    이거 트리네?
    n의 조상중에 m이 있으면 만들수 있는 거잖아.
    n에 계속 /2하면 되는건가?

이렇게 됐을 때는 트리인데
반대로 나눠갈 때는 값이 겹치기도 해서..

계속 겹치나?

먼저 도착한게 더 느릴 수 있나? bfs라 그럴 일 없어.
*/