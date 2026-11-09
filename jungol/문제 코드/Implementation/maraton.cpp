#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<string> board(n);
    for (auto& s : board) cin >> s;

    char winner = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (board[i][k] == '.') continue;
            if (i + 2 < n) {
                if (k - 2 >= 0 and board[i][k] == board[i+1][k-1] and board[i+1][k-1] == board[i+2][k-2]) {
                    winner = board[i][k];
                }
                else if (k + 2 < n and board[i][k] == board[i+1][k+1] and board[i+1][k+1] == board[i+2][k+2]) {
                    winner = board[i][k];
                }
                else if (board[i][k] == board[i+1][k] and board[i+1][k] == board[i+2][k]){
                    winner = board[i][k];
                }
            }            
            if (k+2 < n and board[i][k] == board[i][k+1] and board[i][k+1] == board[i][k+2]){
                winner = board[i][k];
            }

            if (winner) break;
        }

        if (winner) break;
    }

    if (winner) cout << winner;
    else cout << "ongoing";
    
    return 0;
}   