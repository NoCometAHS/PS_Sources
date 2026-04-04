#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr LL inf = 9e8;

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            LL x, y;
            cin >> x >> y;

            cout << i << " " <<  x + inf << ' ' << y + 1 << "\n";
        }
    }
    
    return 0;
}

// 점 n개가 있고, 다른 점 n개를 알아서 만들고, 만들어질 n개의 직선들이 교차하지 않게 하라.
// 2n개 의 점은 같은 점에 있으면 안 됨.

/*
답이 되는 경우만 줌.
점은 정수 좌표임.

일단 길이가 1보다 길어져야 하는 일이 생길거야.
근데 점이 100개 밖에 없어.

(x, y)가 있으면, (x, + inf, y+1)로 해버리면 안 되나? 안 겹치는 것 같은데,


*/