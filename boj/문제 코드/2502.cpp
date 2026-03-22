#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dp[33];

int dfs(int lv) {
    if (lv <= 1) {
        return dp[lv];
    }
    else if (dp[lv]) return dp[lv];

    return dp[lv] = dfs(lv-1) + dfs(lv-2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    dp[1] = 1;
    
    dfs(30);


    for (int i = 1; true; i++) {
        if ((m - dp[n-2] * i) % dp[n-1]) continue;

        int a = i, b = (m - dp[n-2] * i) / dp[n-1];

        cout << a << '\n' << b;

        break;
    }

    return 0;
}// 1 1 2 3 5 8 13 21
/*
x = a + b
a = b + c
b = c + d
c = d + f

b = 2d + f
a = 2d + f + d + f
a = 3d + 2f
x = 3d + 2f + 2d + f
x = 5d + 3f


a
b
c = b + a


x = 2*b + c ... 하나의 변수만 남겠는데?
아니고
계수가 피보나치 수열이고
디오판토스 방정식이네.
*/