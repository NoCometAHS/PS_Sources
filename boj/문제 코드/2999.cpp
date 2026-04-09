#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;

    int n = str.length();
    int r, c;

    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        r = i, c = n / i;
    }

    vector<vector<char>> board(r, vector<char>(c));
    for (int i = 0; i < c; i++) {
        for (int k = 0; k < r; k++) board[k][i] = str[i*r + k];
    }

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) cout << board[i][k];
    }

    return 0;
}