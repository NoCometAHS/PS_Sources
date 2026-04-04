#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int dfs(int s, int e, string& str, vector<vector<int>>& dp) {
    if (s >= e) return 0;
    if (dp[s][e] != -1) return dp[s][e];
    if (str[s] == str[e]) return dp[s][e] = dfs(s+1, e-1, str, dp);
    
    return dp[s][e] = min({
        dfs(s, e-1, str, dp) + 1,
        dfs(s+1, e, str, dp) + 1,
        dfs(s+1, e-1, str, dp) + 1
    });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        string str;
        cin >> str;

        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        cout << dfs(0, n-1, str, dp) << '\n';
    }
    return 0;
}
// 최소의 편집거리에 있는 펠린드롬이 있을 때, 그 편집 거리를 출력하라.
// 연산은, 추가, 삭제, 변환
/*
최소 편집거리는 dp로 풀 수 있다고 본 것 같은데?

최대 3000 길이의 문자열에 대해서만 생각하면 됨.

펠린드롬으로 최소한의 연산으로 가려면, 이미 펠린드롬인 서브 스트링을 이용해서 찾아야하는 게 아닐까?

일단 |s|번 연산으로 무조건 펠린드롬을 만들 수 있어.
어떻게 더 줄일 수 있을까? 이미 펠린드롬인 부분 빼고 바꾸기.

dp[st][en] = [st, en]을 펠린드롬으로 만드는 최소 연산 수
dp[s][e] = min{
    dp[s][e-1] + 1,
    dp[s+1][e] + 1,
    dp[s+1][e-1] + 1
}

삭제 연산은 어떻게 표현하지?

일단 그냥 편집 거리는?

dp[i][k] = min{
    dp[i][k-1] + 1,
    dp[i-1][k] + 1,
    dp[i-1][k-1] + 1
}

dp[i][k] = i까지 

---

뭔가를 추가해서 펠린드롬이 되는 경우가 있나?
추가 해서 되는 거였으면 다른 연산으로 대체를 못 하나?
그냥 바꾸기 연산만으로 펠린드롬 만드는게 최적이 아닐까?

asfddsa

babababac

adsd
가 있네 ㅋㅋ;
*/