#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        int n, y, r;
        cin >> n >> y >> r;

        cout << min(n, y/2 + r) << '\n';
        
    }
    return 0;
}