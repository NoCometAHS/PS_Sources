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

    unordered_map<int, unordered_set<int>> col, row;

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;

        col[c].clear();
        row[r].clear();

        col[c].insert(r);
        row[r].insert(c);
    }
    
    int ans = 0;
    for (auto& s : col) {  
        int c = s.first;
        for (auto& r : s.second) {
            ans += row[r].count(c);
        }
    }

    cout << ans;
    return 0;
}

//ac이후 49분 남음