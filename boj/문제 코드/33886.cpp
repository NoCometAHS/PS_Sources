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

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        for (int k = 1; k < i; k++) {
            if (arr[k] >= i - k + 1) {
                dp[i] = min(dp[i], dp[k-1] + 1);
            }
        }
    }

    cout << dp[n];

    return 0;
}

/*
최대한 한 덩이로 뭉쳐라.

오른쪽에서 왼쪽으로 보면 되는 거 아닌가?
ㄴㄴ

큰수먼저 보는 것도 ㄴㄴ
5 1 1 4 1 1 1 1

그래프로 만들었을 때 최단 거리 아님?
이거 dag인데

dp로 될 것 같은데?

*/