#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;


        TwoVector<int> board(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                char ch;
                cin >> ch;

                board[i][k] = ch - '0';
            }
        }


        TwoVector<bool> chk(n, vector<bool>(m, false));
        vector<bitset<5>> ansBit(1, 0);
        int leftNum = n * m;
        int x = 0, y = 0, numIdx = 5;
        int dir = 0;

        while (leftNum--) {
            if (numIdx == 0) {
                ansBit.push_back(0);
                numIdx = 5;
            }

            chk[y][x] = true;
            ansBit.back()[--numIdx] = board[y][x];

            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || chk[ny][nx]) {
                dir = (dir + 1) % 4;

                nx = x + dx[dir];
                ny = y + dy[dir];
            }

            x = nx;
            y = ny;
        }

        string ans;
        for (auto& i : ansBit) {
            int toNum = i.to_ullong();
            
            if (toNum == 0) ans.push_back(' ');
            else ans.push_back('A' + toNum - 1);
        }

        while (ans.back() == ' ') ans.pop_back();

        cout << ans << '\n';
    }
    return 0;
}
