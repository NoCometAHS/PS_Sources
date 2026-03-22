#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int w, h , x, y, p;
    cin >> w >> h >> x >> y >> p;

    int cx1, cy1, cx2, cy2, r = h/2;
    cx1 = x, cy1 = y + r;
    cx2 = x + w, cy2 = cy1;

    r *= r;

    int ans = 0;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;

        bool f = false;
        f |= x <= a && a <= x + w && y <= b && b <= y + h;
        f |= (cx1 - a)*(cx1 - a) + (cy1 - b) * (cy1- b) <= r;
        f |= (cx2 - a)*(cx2 - a) + (cy2 - b) * (cy2- b) <= r;

        ans += f;
    }

    cout << ans;

    return 0;
}

// 사각형 안에 있는가?
// 원 중심과 거리가 반지름보다 짧은가?