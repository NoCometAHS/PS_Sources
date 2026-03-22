#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char, iipair> dir{{'U', {0,-1}}, {'R', {1, 0}}, {'D', {0,1}}, {'L', {-1,0}}};

    int n, m;
    string str;
    cin >> n >> m >> str;

    int x = 0, y = 0; 
    bool ans = false;
    vector<iipair> deltas;
    
    for (auto& d : str) {   
        auto [dx, dy] = dir[d];

        x += dx, y += dy;
        deltas.push_back({x, y});

        ans |= x == 0 && y == 0;
    }

    deltas.pop_back();

    
    int absX = abs(x), absY = abs(y);

    if (!ans && m > 1) {
        for (auto [dx, dy] : deltas) {
            if (ans) break;
            if (x == 0 && dx != 0) continue;
            if (y == 0 && dy != 0) continue;
            if (dx * x > 0 || dy * y > 0) continue;

            dx = abs(dx), dy = abs(dy);

            int a, b;
            if (x == 0) {
                if (dy == 0 || dy % absY) continue;

                a = b = dy / absY;
            }
            else if (y == 0) {
                if (dx == 0 || dx % absX) continue;

                a = b = dx / absX;
            }
            else {
                if (dx == 0 || dy == 0 || dx % absX || dy % absY) continue;

                a = dx / absX;
                b = dy / absY;
            }

            if (a != b) continue;
            ans = a <= (m-1);
        }

    }

    cout << (ans ? "YES" : "NO");

    return 0;
}

/*
k == 1
그냥 문자열 돌면서 확인

k > 1
문자열 같은거 뒤로 하나만 더 붙이고 돌면서 확인하기.
- 더 붙여야지 되는 것도 있는 것 같은데.

이동하면서 만들어진 원점으로부터 변화량을 다 저장하기.
마지막 위치도 저장.

변화량 + (마지막 위치) *min(k, x) = 0 : x는 자연수
가 있으면 되는 거 아니냐.

*/
