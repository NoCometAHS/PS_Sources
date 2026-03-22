#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, j, s, h, d;
    cin >> n >> j >> s >> h >> d;

    vector<string> board(3);
    for (auto& s : board) cin >> s;

    int st = 0, ht = 0, ut = 0;
    for (int i = 0; i < n; i++) {
        if (board[0][i] == 'v') ut++;
        else if (board[1][i] == '^') ht++;
        else if (board[2][i] == '^') st++;
    }

    s -= ut;
    j -= st;

    if (s < 0) h += s*d;
    if (j < 0) h += j*d;
    
    while (ht--) {
        if (j >= 2) j -=2;
        else h -= d;
    }

    if (h > 0) cout << h;
    else cout << -1;

    return 0;
}
