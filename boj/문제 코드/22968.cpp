#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<LL> dp(50);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 50; i++) dp[i] = dp[i-1] + dp[i-2] + 1;

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        cout << upper_bound(dp.begin(), dp.end(), n) - dp.begin() - 1 << '\n';
    }
    return 0;
}


//2^h - 1 = 노드 개수
//2^h = n + 1
//h = log_2(n+1);