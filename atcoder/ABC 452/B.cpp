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

    TwoVector<char> board(n, vector<char>(m, '.'));

    for (int i = 0; i < n; i++) {
        board[i][0] = board[i][m-1] = '#';
    }

    
    for (int i = 0; i < m; i++) {
        board[0][i] = board[n-1][i] = '#';
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cout << board[i][k];
        }
        cout << '\n';
    }
    return 0;
}