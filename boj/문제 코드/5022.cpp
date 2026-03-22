#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int r, c;

int bfs(iipair start, iipair end, TwoVector<bool>& chk) {
    TwoVector<int> dist(r, vector<int>(c, 1e9));
    TwoVector<iipair> track(r, vector<iipair>(c));

    queue<iipair> que;
    que.push(start);
    dist[start.second][start.first] = 0;
    track[start.second][start.first] = {-1, -1};

    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        if (x == end.first && y == end.second) break;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || nx >= c || ny  < 0 || ny >= r) continue;
            if (dist[ny][nx] != 1e9 || (chk[ny][nx] && (nx != end.first || ny != end.second))) continue;

            dist[ny][nx] = dist[y][x] + 1;
            track[ny][nx] = {x, y};
            que.emplace(nx, ny);
        }
    }

    if (dist[end.second][end.first] == 1e9) return 1e9;

    iipair cur = end;
    while (cur.first != -1) {
        chk[cur.second][cur.first] = true;

        cur = track[cur.second][cur.first];
    }

    return dist[end.second][end.first];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    r++, c++;

    vector<iipair> arr(4);
    TwoVector<bool> chk(r, vector<bool>(c, false));

    for (auto& [x, y] : arr) {
        cin >> y >> x; 
        chk[y][x] = true;
    }


    int ret1 = bfs(arr[0], arr[1], chk) + bfs(arr[2], arr[3], chk);

    for (auto& v : chk) {
        for (int i = 0; i < c; i++) v[i] = false; 
    }
    for (auto& [x, y] : arr) {
        chk[y][x] = true;
    }

    int ret2 = bfs(arr[2], arr[3], chk) + bfs(arr[0], arr[1], chk);

    if (ret1 >= 1e9 && ret2 >= 1e9) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << min(ret1, ret2);
    }

    return 0;
}
