#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<unordered_set<int>> pre(n);
    vector<unordered_set<int>> cur(n);
    vector<unordered_set<int>> chk(n);
    vector<unordered_set<int>> chk2(n);
    vector<iipair> edges;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        edges.emplace_back(i, a);
        edges.emplace_back(i, b);
    }


    //2번째만 쓴 결과
    pre[0].insert(0);

    for (int i = 0; i < 99; i++) {
        for (int k = 1; k < edges.size(); k++) {
            auto& [from, to] = edges[k];

            for (auto& num : pre[from]) {
                cur[to].insert(num+1);
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (auto& a : cur[i]) chk[i].insert(a);
        }

        swap(pre, cur);
        for (int i = 0; i < n; i++) {
            cur[i].clear();
        }
    }

    // 첫번째만 쓴 결과
    for (int i = 0; i < n; i++) {
        pre[i].clear();
    }
    pre[0].insert(0);

    for (int i = 0; i < 99; i++) {
        for (int k = 0; k < edges.size(); k++) {
            if (k==1) continue;

            auto& [from, to] = edges[k];

            for (auto& num : pre[from]) {
                cur[to].insert(num+1);
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (auto& a : cur[i]) chk2[i].insert(a);
        }

        swap(pre, cur);
        for (int i = 0; i < n; i++) {
            cur[i].clear();
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << " : ";
    //     for (auto&  a : chk[i]) cout << a << ' ';
    //     cout << '\n';
    // }

    bool ans= false;
    for (int i = 10; i < 100; i++) {
        if (chk[0].count(i) && chk2[0].count(i)) continue;

        ans = true;
        cout << i;
        break;
    }

    if (!ans) cout << -1;

    return 0;
}

/*
유향 그래프에서 k번 이동했을 때 내가 걸릴 일이 절대 없어야해.

얘들이 내가 걸리도록만 움직인다고 생각하자.
    1. 일단 내가 보내는 두 경우 모두 돌아오는 사이클이 존재해야 해.
    2. 수가 크면 사이클을 빙빙 돌리겠지, 근데 내가 포함된 사이클이면 쉽게 안 되게 만들 껄.

모든 최소 사이클 길이들을 찾고, 그 수들로 10부터 99까지 만들 수 없는 수 있는 지 찾기.
-> 사이클에서 혹처럼 튀어 나가 있는 경우, 수를 더 써서 힘들 것 같은데.

그래프 탐색이 아니네?
dp? 게임이론?

베스킨라빈스31 같은 느낌인가
벨만포드 느낌으로 그냥 할 수 있지 않을까?

이게 내가 마음대로 보낼 수 있는 부분에서 문제야
4
2 4
3 3
1 1
1 1
로 모든 숫자를 만들 수 있는 것처럼 보여도
내가 4로만 보내면 홀수 절대 못 만들어.

그럼 진짜 나 하나만 보내게 박아두면?
4
2 ?
3 3
1 4
3 3
..

일 때 운이 안 좋아서 2로만 보내면 10에서 99의 수 다 만들 수 없나?? 

4
2 4
1 3
1 1
1 1

4를 고르면 안 되는데, 2를 고르면 다 만들 수 있어.

일단 내가 2쪽다 골고루 고르는건 손해야.
한 쪽만 고르게?

?? 이게 틀리면 뭐지.
*/