#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int dx[8] = {1, 2, 2, 1, -1, -2, -2 ,-1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, x, y;
    cin >> n >> x >>  y;

    if (n == 3) {
        if (x == 2 && y == 2) cout << 1;
        else cout << 4;
    }
    else {
        if (n % 2)
            cout << n*n/2 + ((x + y + 1) % 2);
        else cout << n*n/2;
    }
    return 0;
}

// 시뮬은 ㅂㄱㄴ.
/*
말은 한 번 움직임으로서 자신의 색을 바꾼다.
2번씩 움직여야 한다면 자신의 색을 못 바꿔.
나이트의 여행처럼 어떻게든 움직이면 자신의 색은 다 갈 것 같은데?

다른 곳으로 2번 움직일 거리만 있으면 다 갈 수 있는 건가?
안쪽으로 돌면서 다 가는 것 같은데.
*/