#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

using edge = pair<iipair, iipair>;

int setTree[100100];

void init(){
    iota(setTree, setTree + 100100, 0);
}

int getPar(int c) {
    if (c == setTree[c]) return c;
    return setTree[c] = getPar(setTree[c]);
}

void unionSet(int a, int b) {
    a = getPar(a), b = getPar(b);

    if (a == b) return;

    setTree[b] = a;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    int idx = 1;
    for (auto& [w, e] : edges) {
        cin >> e.first >> e.second >> w.first;

        w.second = idx++;
    }

    sort(edges.begin(), edges.end());

    init();
    LL maxWeightEdge = 0;
    LL sum = 0;
    for (auto& [w, e] : edges) {
        if (getPar(e.first) == getPar(e.second)) continue;

        unionSet(e.first, e.second);
        maxWeightEdge = w.first;
        sum += w.first;
    }


    priority_queue<edge> pq;
    for (auto& [w, e] : edges) {
        if (w.first > maxWeightEdge) continue;

        pq.emplace(w, e);
    }

    init();
    LL MBSTsum = 0;
    vector<int> ans;
    while (!pq.empty()) {
        auto [w, e] = pq.top();
        pq.pop();

        if (getPar(e.first) == getPar(e.second)) continue;

        unionSet(e.first, e.second);
        MBSTsum += w.first;
        ans.push_back(w.second);
    }

    cout << "NO\n";
    if (MBSTsum == sum) {
        cout << "NO\n";
    }
    else {
        cout <<"YES\n";
        for (auto& i : ans) cout << i << '\n';
    }



    return 0;
}

// mst면서 mbst가 아닌것, mbst면서 mst가 아닌것
/*
mst는 사이클에 속한 간선 제거 하면서 만든다고 할 수 있어.

가중치의 최댓값이 최소?
최댓값이 사이클에 있다
- 최댓값을 제거 할 수 있다?
-- 흠
- 최댓값을 제거 할 수 있다?
-- 흠

최댓값이 사이클에 없다
- 이러면 mst == mbst, mbst == mst

주어진 그래프가 연결 그래프이면 ㅇㅋ 뭐 없는 듯?

mst는 값이 같다면 다르게 만들 수 있어. 만약에 모든 간선 가중치가 다르다면, mst는 유일해.

mbst는 


잠만잠ㄴㅏㅁ.
어떤 그래프에서 mbst란?
얘도 똑같이 최솟값만 써가면서 만들어야 함.
근데 한번 쓴 간선보다 작은 간선은 마음대로 써도 됨.
이러면서 mst랑 다르게 만들 수 있어.


근데 mst인데 mbst가 아닌경우??
없는거 아냐?
그런듯

mst인데 mbst가 아닐 경우는 무조건 mbst의 값이 더 작은 것 뿐임. mbst는 최소 mst의 값이랑 같으니깐
위 경우는 mst를 잘 못 만든거지.
즉 mst이면 무조건 mbst


mbst인데 mst가 아닌 경우를 찾아야 하는데,
n^2만에 구할 수는 있을 듯.

간선 최댓값의 최솟값의 가중치인 값을 찾고, 큰 순서대로 박아버리면 됨.

그러면 간선 최댓값의 최솟값은 어떻게 찾지?
mst 값이 mbst값이라며


그럼
mst를 구해서, 최댓값을 찾는다.
그 최댓값 밑으로 간선들 pq에 다 넣고, 큰 값먼저 뽑는다.


*/