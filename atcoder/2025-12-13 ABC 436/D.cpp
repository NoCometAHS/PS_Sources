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

    iipair delta[4] = {{-1, 0},{1, 0},{0, 1},{0, -1}};

    vector<string> board(n);
    for (auto& s: board) cin >> s;

    TwoVector<int> graph(n*m);

    map<char, vector<int>> warps;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            int cur = i * m + k;

            if (board[i][k] == '#') continue;
            if (board[i][k] != '.') {
                warps[board[i][k]].emplace_back(cur);
            }

            for (auto [dx, dy] : delta) {
                int nx = k + dx, ny = i + dy;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[ny][nx] == '#') continue;
                int next = ny * m + nx;

                graph[cur].push_back(next);
            }
        }
    }

    vector<int> chk(n*m, 0);
    queue<int> que;

    if (board[0][0] != '#') {
        que.push(0);
        chk[0] = 1;
    }

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (auto& next : graph[cur]) {
            if (chk[next]) continue;

            chk[next] = chk[cur] + 1;
            que.push(next);
        }

        if (board[cur/m][cur%m] != '.') {
            auto& warp = warps[board[cur/m][cur%m]];

            while(!warp.empty()) {
                int next = warp.back();
                warp.pop_back();

                if (chk[next]) continue;

                chk[next] = chk[cur] + 1;
                que.push(next);
            }
        }
    }

    cout << chk.back() - 1;
    return 0;
}

/*
모든 칸이 워프로 채워져 있으면 메모리, 시간 초과 나겠다.

한번 가본 워프를 또 탈 필요는 없으니깐 지우자.

무처버린 구현 실수!!!!

*/