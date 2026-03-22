#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        bool row[9] = {0,}, col[9] = {0,};
        bool ans = true;

        while (m--) {
            int c, r;
            cin >> c >> r;
            
            if (row[r]) ans = false;
            if (col[c]) ans = false;

            row[r] = true;
            col[c] = true;
        }

        if (ans) {
            cout << "SAFE\n";
        }
        else {
            cout << "NOT SAFE\n";
        }

    }
    return 0;
}
