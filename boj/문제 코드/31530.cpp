#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

constexpr LL mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<LL>> dp(1100100, vector<LL>(4, 0));
    for (auto& i : dp[0]) i = 1;
    for (auto& i : dp[1]) i = 1;

    for (int h = 2; h < 1100100; h++) {
        dp[h][0] = dp[h-1][0] * dp[h-1][0] + dp[h-1][0] * dp[h-2][0];
        dp[h][1] = dp[h-1][1] * dp[h-1][1] + dp[h-1][1] * dp[h-2][1];
        dp[h][2] = dp[h-1][2] * dp[h-2][2] + dp[h-1][2] * dp[h-2][2];
        dp[h][3] = dp[h-1][3] * dp[h-1][3] + dp[h-1][3] * dp[h-2][3] + dp[h-1][3] * dp[h-2][3];
        for (auto& i : dp[h]) i %= mod;
    }


    int tc;
    cin >> tc;

    map<set<int>, int> order{
        {{0, 1}, 0},
        {{0, -1}, 1},
        {{1, -1}, 2},
        {{0, 1, -1}, 3}
    };

    while (tc--) {
        int h, s;
        cin >> h >> s;
        set<int> se;

        while (s--) {
            int e;
            cin >> e;
            se.insert(e);
        }

        if (se.size() == 1) {
            cout << 1 << '\n';
            continue;
        }
        cout << dp[h][order[se]] << '\n';
    }
    
    return 0;
}

// 왼쪽, 오른쪽 서브트리 높의 차가, 집합 S안에만 있는 트리가 AVLM 트리
// S는 {0, 1, -1}의 공집합이 아닌 서브트리.
// AVLM 트리의 높이 S가 주어질 때 가능한 트리 개수는?

/*
h가 좀 크니 브포는 못 하겠고.
뭔가 mod로 나눠야 하는 거 보면 dp일 것 같기도 하고.

높이 차가 0만 있는 트리는 완전 이진트리고
높이 차가 -1, 1만 있는 트리는 다른 높이 차 -1, 1만 있는 얘들을 서브 트리로 갖는 것 같은데?

높이가 1부터 h-1까지의 AVLM 트리의 개수가 있다고 하면,
h인 avlm트리의 개수는?

dp[높이][높이 차가  0, 1,-1 {S}] 

s에 뭐가 있냐에 따라 다르겠다.
s에 0이 있다면,
dp[h][0] = 1 // 0
dp[h][1] = dp[h-1][1] * dp[h-2][1]  // 1
dp[h][2] = dp[h-1][2] * dp[h-2][2] // -1

dp[h][3] = dp[h-1][3] * dp[h-1][3] + dp[h-1][1] // 0, 1
dp[h][4] = dp[h-1][2] * dp[h-2][2] + dp[h-1][2]// 0, -1
dp[h][5] = dp[h][1]  + dp[h][2]// 1, -1
dp[h][6] = dp[h-1][3] * dp[h-1][3] + dq[h][2] + dq[h][1] // 0, -1, 1


마지막에 필요한 것들만 알아서 곱하면 되나. ㄴㄴ
dp 만들어 가면서 끝내야 함.

dp식이 좀 틀린 것 같은데?

각 조건들은 0, 1, 2의 조합으로 바로 나타낼 수 있는 것 같은데
0, 1, 2은 높이가 어떻든 1 아닌가?
-> ㄴㄴ 자식들로 0, 1, 2로만 이루어진 놈들만 있는 게 아니야.

3, 4, 5, 6 으로만 dp를 구성해나가기?

*/
