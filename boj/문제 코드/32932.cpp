#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    set<iipair> obstacles;
    while (n--) {
        int x, y;
        cin >> x >> y;
        obstacles.emplace(x, y);
    }

    map<char, iipair> move{{'U', {0, 1}},{'D', {0, -1}},{'R', {1, 0}},{'L', {-1, 0}}};
    int x = 0, y = 0;
    for (int i = 0; i < m; i++) {
        char ch;
        cin >> ch;

        int nx = x + move[ch].first, ny = y + move[ch].second;
        if (obstacles.count({nx,ny})) continue;

        x = nx, y = ny;
    }

    cout << x << ' ' << y;
    return 0;
}
