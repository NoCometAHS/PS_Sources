#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int treeSet[202020];
int blackCnt[202020];
bool isBlack[202020];

void init() {
    iota(treeSet, treeSet + 202020, 0);
}

int findPar(int a) {
    if (a == treeSet[a]) return a;
    return treeSet[a] = findPar(treeSet[a]);
}

void union_set(int a, int b) {
    a = findPar(a), b = findPar(b);

    if (a == b) return;

    blackCnt[a] += blackCnt[b];
    blackCnt[b] = 0;

    treeSet[b] = a;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();

    int n, q;
    cin >> n >> q;

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int u, v;

            cin >> u >> v;
            u--, v--;

            union_set(u, v);
        }
        else if (t == 2) {
            int u;
            cin >> u;
            u--;

            isBlack[u] = !isBlack[u];

            if (isBlack[u]) blackCnt[findPar(u)]++;
            else blackCnt[findPar(u)]--;
        }
        else {
            int u;
            cin >> u;
            u--;
            
            if (blackCnt[findPar(u)] == 0) cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}

/*
간선 없는 무향 그래프. 정점 n개.

처음에는 정점 하얀색.

q개의 쿼리
1. 간선 추가.
2. v가 하얀색, 검정색 스위치 오프.
3. v에서 검정 정점으로 갈 수 있냐. yes or no

----

O(n)은 불가능

----
유니온 앤 파인드로 간선 연결 확인.
정점 노드에서 검정 개수 확인.
*/