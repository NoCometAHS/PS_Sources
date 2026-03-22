#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;


    int ans = -1;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;


        if  (s + t > x) continue;
        ans = max(s, ans);
    }   

    cout << ans;
    return 0;
}
