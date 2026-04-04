#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c;
    cin >> r >> c;

    vector<string> board(r);
    for (auto& s : board) cin >> s;

    vector<int> ans(5, 0);
    for (int i = 0; i < r - 1; i++) {
        for (int k = 0; k < c - 1; k++) {
            
            int cnt = 0;
            bool can = true;

            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 2; x++) {
                    can &= board[i+y][k+x] != '#';
                    cnt += board[i+y][k+x] == 'X';
                }
            }

            if(can) {
                ans[cnt]++;
            }
        }
    }

    for (auto& i : ans) cout << i << '\n';
    return 0;
}