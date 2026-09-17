#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    TwoVector<int> ans(n, vector<int>(n, 0));

    int r = 0, c = (n-1)/2, k = 1;
    ans[r][c] = k;
    
    for (int i = 0; i < n*n - 1; i++) {
        int nr = (r-1+n) % n, nc = (c+1) % n;
        k++;

        if (!ans[nr][nc]) {
            r = nr, c = nc;
            ans[r][c] = k;
        }
        else {
            ans[(r+1)%n][c] = k;
            r = (r+1)%n;
        }
    }

    for (auto& v : ans) {
        for (auto& i : v) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}

//