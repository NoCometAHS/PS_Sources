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

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            int num;
            cin >> num;
            
            ans += num;
        }
    }

    cout << ans;
    return 0;
}
