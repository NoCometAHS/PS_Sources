#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}

/*
N이 50개 밖에 안 돼서
그래프 만들고, 전부 dfs 돌려보면서 브포하면 될 것 같은데?


이동할 수 있는 지 확인하려면
1. x 좌표가 겹쳐있다. -> y좌표 차가 거리
2. x 좌표에 겹치는 부분이 없다 -> 양 끝점의 직선 거리
로 확인해보기.

scc??
*/