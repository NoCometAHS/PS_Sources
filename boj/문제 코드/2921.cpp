#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int ans  = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            ans += i + k;
        }
    }

    cout << ans;
    return 0;
}