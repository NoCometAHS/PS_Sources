#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int r, c;

bool dfs(int start, int cur, int pre, vector<string>& board, TwoVector<int>& cnt, int lv = 500) {
    if (lv == 0) return false;

    int x = cur % c, y = cur / c;

    cnt[y][x]++;

    int go = -1, mn = 1e9;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y  + dy[i];

        if (nx < 0 || ny < 0 || nx >= c || ny >= r || board[ny][nx] == 'X') continue;
        
        int next = ny*c + nx;

        if (next == pre) continue;
        if (next == start) return true;

        if (cnt[ny][nx] < mn) {
            go = next;
            mn = cnt[ny][nx];
        }
    }

    
    if (go != -1 && dfs(start, go, cur, board, cnt, lv-1)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    vector<string> board(r);
    for (auto& i : board) cin >> i;

    TwoVector<int> cnt(r, vector<int>(c, 0));
    bool ans = true;
    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            if (board[i][k] == 'X') continue;

            ans &= dfs(i*c+k, i*c+k, -1, board, cnt);
            
            for (auto& v : cnt) {
                for (auto& i : v) i = 0;
            }
        }
    }

    cout << !ans;

    
    
    return 0;
}
