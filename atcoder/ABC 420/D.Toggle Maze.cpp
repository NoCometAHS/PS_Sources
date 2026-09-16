#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int dx[4] = {0, 1, 0 , -1}, dy[4] = {1, 0, -1, 0};

int h, w;
char board[505][505];
bool canReSwitch[505][505];
bool chk[505][505];

int dfs(iipair cur, char closeChar = 'x') {
    if (board[cur.second][cur.first] == 'G') return 0;

    auto [x, y] = cur;
    int ret, mn = 1e9;

    chk[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx =  + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= w || ny < 0 || ny >= h || chk[ny][nx]) continue;
        if (board[ny][nx] == '#' || board[ny][nx] == closeChar) continue;

        if (board[ny][nx] == '?') {
            ret = dfs({nx, ny}, (closeChar == 'X' ? 'O' : 'X')) + 1;
        }
        else {
            ret = dfs({nx, ny}, closeChar) + 1;
        }

        mn = min(ret, mn);
    }

    if (canReSwitch[y][x]) {
        char oppCloseChar = (closeChar == 'X' ? 'O' : 'X');

        for (int i = 0; i < 4; i++) {
            int nx =  + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h || chk[ny][nx]) continue;
            if (board[ny][nx] == '#' || board[ny][nx] == oppCloseChar) continue;

            if (board[ny][nx] == '?') {
                ret = dfs({nx, ny}, (oppCloseChar == 'X' ? 'O' : 'X')) + 3;
            }
            else {
                ret = dfs({nx, ny}, oppCloseChar) + 3;
            }

            mn = min(mn, ret);
        }
    }

    return mn;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> h >> w;

    iipair start;
    for (int i = 0; i < h; i++) {
        for (int k = 0; k < w; k++) {
            cin >> board[i][k];

            if (board[i][k] == 'S') {
                start = {k, i};
            }
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (board[y][x] != '?') continue;

            int oCnt = 0, xCnt = 0, dotCnt = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                oCnt += board[ny][nx] == 'o';
                xCnt += board[ny][nx] == 'x';
                dotCnt += board[ny][nx] == '.';
            }

            if (dotCnt > 0 || (oCnt > 0 && xCnt > 0)) canReSwitch[y][x] = true;
        }
    }

    int ans = dfs(start);

    if (ans >= 1e9) cout << -1;
    else cout << ans;

    return 0;
}


/*
H행 W열

. : Empty cell.
# : Obstacle cell.
S : Start cell.
G : Goal cell.
o : Open door cell.
x : Closed door cell.
? : Switch cell.

로 배열이 차 있음.

닫힌 문이나, 장애물 아니면 상하좌우로 움직이기 ㄱㄴ.

스위치가면 열린 문 닫히고, 닫힌문 열림.

갈 수 있으면 최소 이동 횟수.
아니면 -1.

---------------
dfs와 bfs 섞기만 해도 풀 수 있을까?
해보는 수 밖에?

그렇게 했을 때, 무한 반복을 하진 않을까?
#
s#
o#
?o?.og
x#
?#
#
-> 위로 갔다가 아래로 갔다가만 함.

단순 탐색으로는 힘든 것 같은데.

---------

스위치 다시 밟기를  제외하고는 다시 밟을 필요가 없나?
없는 거 가 ㅌ은데. -> 예제 1이 다시 밟아야 하는 경우였구연 ㅋㅋ. 모르고 구현 했네.
*/