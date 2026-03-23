#include "bits/stdc++.h"

using namespace std;
using LL = long long;
constexpr LL mod = 1e9 + 7;

LL dfs(int x, int y, vector<vector<LL>>& dp) {
    if (x < 0 || y < 0) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    if (x == 0 && y == 0) return 1;


    return dp[x][y] = (dfs(x-2, y-1, dp) * 3 % mod + dfs(x, y-3, dp)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, y;
    cin >> x >> y;
    vector<vector<LL>> dp(x+1, vector<LL>(y+1, -1));
    cout << dfs(x, y, dp);

    return 0;
}

/*
x개의 1, y개의 0, x+y길이의 이진수

이진수를 3부분으로 나누고
1번째 부분 = 2번째 부분 xor 3번째 부분

모든 가능한 경우의 수는?
---
한 부분당 최대 길이 2000

각 부분에 i번째 수를 채운다고 했을 때,
0, 1, 1
0, 0, 0
1, 1, 0
1, 0, 1
의 경우만 존재함.
즉 
1 둘 0 하나,
0 3개 쓰는 경우만 존재함.

dp[길이][0의 개수][1의 개수]로 구할 수 있나?
dp[2000][3000][3000]?

->
dp[전단계/지금][0의 개수][1의 개수]
dp[2][3000][3000]

dp[3000][3000]와 dfs로 될 것 같은 느낌?

*/