#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c;
    cin >> r >> c;

    vector<vector<int>> board(r, vector<int>(c, -1));

    iipair start, goal;
    vector<vector<iipair>> knights;
    vector<vector<int>> lockedCnt(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            char ch;
            cin >> ch;

            if (ch == '.') continue;

            if (ch == 'K') {
                static iipair kmove[8] = {{1, -2},{2, -1},{2, 1},{1, 2},{-1, 2},{-2, 1},{-2, -1},{-1, -2}};
                
                board[i][k] = knights.size();
                knights.emplace_back();

                for (const auto& [dx, dy] : kmove) {
                    int nx = k + dx, ny = i + dy;

                    if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
                    lockedCnt[ny][nx]++;
                    knights.back().emplace_back(nx, ny);
                }
            }
            else if (ch == 'T') {
                goal = {k, i};
            }
            else {
                start = {k, i};
            }
        }
    }


    iipair delta[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<iipair> que;
    que.push(start);
    board[start.second][start.first] = -2;

    vector<vector<bool>> lockedRook(r, vector<bool>(c, false));

    bool ans = false;
    while (!que.empty()) {
        if (que.front() == goal) ans = true;

        auto [x, y] = que.front();
        que.pop();


        for (const auto& [dx, dy] : delta) {
            
            for (int nx = x + dx, ny = y + dy; nx >= 0 and nx < c and ny >= 0 and ny < r; nx += dx, ny += dy) {
                if (board[ny][nx] == -2) continue;

                int status = board[ny][nx];
                
                if (lockedCnt[ny][nx]) {
                    lockedRook[ny][nx] = true;

                    if (status != -1) break;
                    else { board[ny][nx] = -2; }
                }
                else if (status != -1) {
                    que.emplace(nx, ny);

                    for (const auto& [lockedX, lockedY] : knights[status]) {
                        if (--lockedCnt[lockedY][lockedX] == 0) {
                            if (lockedRook[lockedY][lockedX]) que.emplace(lockedX, lockedY);
                        }
                    }

                    board[ny][nx] = -2;
                    break;
                }
                else {
                    que.emplace(nx, ny);
                    board[ny][nx] = -2;
                }
            }
        }
    }

    cout << (ans ? "yes" : "no");

    return 0;
}