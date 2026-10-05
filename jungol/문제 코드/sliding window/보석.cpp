#include "bits/stdc++.h"

using namespace std;

using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, T, K;
    cin >> N >> M >> T >> K;

    vector<iipair> points(T);
    vector<int> xs, ys;

    for (auto& [x, y] : points) {
        cin >> x >> y;

        xs.push_back(x);
        ys.push_back(y);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());


    int ans = 0;
    int ansx, ansy;
    for (auto& ldy : ys) {
        for (auto& ldx : xs) {
            int t = 0;
            for (auto& [x,y] : points) {
                if (ldx <= x and x <= ldx + K and ldy <= y and y <= ldy + K) t++;
            }

            if (ans < t) {
                ansx = ldx;
                ansy = ldy+K;
                ans = t;
            }
            
        }
    }

    cout << ansx << " " << ansy << '\n';
    cout << ans;

    return 0;
}

/*
정사각형의 네 변 중 하나는 금강석이 포함될것이다.
-> 스위핑? 슬라이딩 윈도우? 쨌든 쭉 흩기

x축만 있으면 그거면 충분하겠는데
y축은?

뭔가 다른 발견이 필요해 보임.

맨 왼쪽 아래 점에 대해서, 정사각형의 왼쪽 아래 꼭짓점에 위치시킨다.
-> 이거 확인 한 이후로 이 점은 다시는 확인 안 해도 된다.

그다음 왼쪽 아래에 있는 것을 보면?, 똑같이  정사각형의 왼쪽 아래 꼭짓점에 위치시켜서.
ㄴㄴㄴ.
정사각형의 각 변에 점이 하나씩 있는 경우를 못 봐.

점이 100개 밖에 안 되네.

모든 y에 대해서 점에대해 스위핑 하는 느낌?
y좌표에 대해서도 모든 점의 y좌표에 대해서만 하면 되잖아.
스위핑이라기 보단 슬라이딩 윈도우 같은데.

*/