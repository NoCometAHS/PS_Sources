#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (auto& s : board) cin >> s;

    bool ans = false;
    for (int y = 0; y < n-1; y++) {
        for (int x = 0; x < m-1; x++) {
            bool flag = true;
            for (int dy = 0; dy < 2; dy++) {
                for (int dx = 0; dx < 2; dx++) {
                    flag &= board[y+dy][x+dx];
                }
            }

            ans |= flag;
        }
    }

    cout << ans;

    return 0;
}

/*
어떤 모양이든, 2*2 정사각형 있으면 무조건 있는거잖아.
*/