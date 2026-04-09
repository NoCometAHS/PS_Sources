#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (auto& s : board) cin >> s;

    int x, y;
    cin >> y >> x;


    vector<vector<char>> ans(n*2, vector<char>(m*2));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) ans[i][k] = board[i][k];
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) ans[i][m+k] = board[i][m-k-1];
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m*2; k++) ans[n+i][k] = ans[n - i - 1][k];
    }

    ans[y-1][x-1] = (ans[y-1][x-1] == '.' ? '#' : '.');

    for (auto& v: ans) {
        for (auto& i : v) cout << i;
        cout << '\n';
    }
    return 0;
}