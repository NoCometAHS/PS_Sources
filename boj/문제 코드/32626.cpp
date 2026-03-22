#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    iipair a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    
    if (a > b) swap(a, b);
    if (a.first == b.first && b.first == c.first ) {
        if (a.second < c.second && c.second < b.second) cout << 2;
        else cout << 0;
    }
    else if (a.second == b.second && b.second == c.second) {
        if (a.first < c.first && c.first < b.first) cout << 2;
        else cout << 0;
    }
    else {
        if (a.first == b.first || a.second == b.second) cout << 0;
        else cout << 1;
    }
    
    return 0;
}

