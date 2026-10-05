#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int K, L, N;
    cin >> K >> L >> N;

    vector<LL> arr(N);
    for (auto& i : arr) cin >> i;

    vector<LL> tree(N+2, 0);

    LL ans = 0;
    for (const LL& w : arr) {
        int cur = 0;
        while (true) {
            int mn = 1e9, mnNode;
            
            bool flag = true;
            cur *= K;
            
            for (int i = 1; i <= K; i++) {
                if (cur+i > N) {
                    mn = 0;
                    mnNode = cur+i;

                    flag = true;
                    break;
                }
                else if (mn > tree[cur+i]) {
                    mn = tree[cur+i];
                    mnNode = cur+i;

                    flag = false;
                }
            }

            if (flag) break;

            cur = mnNode;
            ans += mn;
            tree[mnNode] += w;


        }
        
    }

    cout << ans;

    return 0;
}


/*
k-ary l level 트리.


토끼를 가장 적게 만나서 적(리프)으로 간다.

그런 경로가 여러개일 수 있다.
한 번에 한 자식 노드로.
지금 경로가 가장 적게 토끼를 만나는 것을 유지 하는,
가장 왼쪽의 노드로,
리프에 갈 때까지.

i 번째 미션 후에 경로의 간선에 토끼를 영원히 w_i 늘린다.

n까지 전부 다 하면 얼마나 많은 토끼를 만나는가.

---

절대로 트리 자체를 표현 못 하고요.

일단 레벨로 내려가는 간선이 가득 찰 때까지는 토끼 만나는 횟수가 안늘어
n은 저장할만한 한데.

저장할 수 있을 만큼 저장하고 쓰면 되는 거 아닌가
한 번 갈때마다 저장이 필요한 간선이 늘어나는 거니깐 n개 정도만..

가장 작은 경로를 선택해 나간다는 점이 문제가 있네.
*/