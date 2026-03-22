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

    vector<string> board(n);
    for (auto& s : board) {
        cin >> s;
    }

    vector<string> c;

    for (int i = 0; i < n; i++) {
        string a;
        for (int k = 0; k < m; k++) {
            if (board[i][k] == '#') {
                if (a.length() > 1) c.push_back(a);
                a = "";
            }
            else {
                a += board[i][k];
            }      
        }

        if (a.length() > 1) c.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        string a;
        for (int k = 0; k < n; k++) {
            if (board[k][i] == '#') {
                if (a.length() > 1) c.push_back(a);
                a = "";
            }
            else {
                a += board[k][i];
            }      
        }

        if (a.length() > 1) c.push_back(a);
    }
    
    sort(c.begin(), c.end());
    cout << c.front();
    return 0;
}
