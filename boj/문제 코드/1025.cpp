#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

bool isSquareNumber(string num) {

    LL numInt = stoll(num);

    LL s = sqrt(numInt);

    return s * s == numInt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    LL ans = -1;


    for (int dx = -m; dx <= m; dx++) {
        for (int dy = -n; dy <= n; dy++) {
            if (dx == 0 && dy == 0) continue;

            for (int stX = 0; stX < m; stX++) {
                for (int stY = 0; stY < n; stY++) {

                    string res;
                    for (int x = stX, y = stY; x >= 0 && y >= 0 && x < m && y < n; x += dx, y += dy) {
                        res += arr[y][x];

                        if (isSquareNumber(res)) {
                            ans = max(ans, stoll(res));
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}

/*
대각선으로 선택하기?
브포?
*/