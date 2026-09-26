#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto& i : a) cin >> i;
        for (auto& i : b) cin >> i;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(0, a[i] - b[i]);
        }
        cout << ans + 1 << '\n';
        
    }
    return 0;
}

//accepted
