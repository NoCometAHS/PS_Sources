#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, h;
    cin >> n >> h;

    int ans = 0;
    while (n--) {
        int num;
        cin >> num;

        h -= num;
        ans++;

        if (h <= 0) break;
    }

    if (h > 0) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;
}
