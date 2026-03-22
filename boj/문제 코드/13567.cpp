#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dx[]= {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    int dir = 0;
    int x = 0, y = 0;
    bool f = true;

    while (m--) {
        string q;
        int d;
        cin >> q >> d;

        if (q.front() == 'M') {
            int nx = x + dx[dir] * d, ny = y + dy[dir] * d;

            if (nx < 0 || ny < 0 || nx > n || ny > n) {
                f = false;

                break;
            }

            x = nx, y = ny;
        }
        else {
            if (d) {
                dir = (dir + 1) % 4;
            }
            else {
                dir = (dir + 3) % 4;
            }
        }
    }

    if (f) {
        cout << x << ' ' << y;
    }
    else {
        cout << -1;
    }
    
    return 0;
}
