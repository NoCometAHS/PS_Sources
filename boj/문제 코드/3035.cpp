#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, zn, zm;
    cin >> n >> m >> zn >> zm;

    vector<string> board(n);
    for (auto& s : board) cin >> s;


    for (int i = 0; i < n * zn; i++) {
        for (int k = 0;  k < m * zm; k++) {
            cout << board[i/zn][k/zm];
        }
        cout << '\n';
    }
    return 0;
}