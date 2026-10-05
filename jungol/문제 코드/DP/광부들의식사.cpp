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

    string str;
    cin >> str;

    int dp[2][4][4][4][4];
    memset(dp, -1, sizeof(dp));
    dp[1][0][0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        int food = (str[i] == 'M' ? 1 : (str[i] == 'F' ? 2 : 3));
        
        auto score = [&](int a, int b, int c) {
            set<int> s{a,b,c};
            return (int) (s.size() - s.count(0));
        };


        for (int a1 = 0; a1 < 4; a1++) {
            for (int a2 = 0; a2 < 4; a2++) {
                for (int b1 = 0; b1 < 4; b1++){
                    for (int b2 = 0; b2 < 4; b2++){
                        int cur = dp[(i+1)%2][a1][a2][b1][b2];
                        if (cur < 0) continue;

                        dp[i%2][a2][food][b1][b2] = max(dp[i%2][a2][food][b1][b2], cur + score(a1, a2, food));
                        dp[i%2][a1][a2][b2][food] = max(dp[i%2][a1][a2][b2][food], cur + score(b1, b2, food));
                    }
                }
            }
        }

        memset(dp[(i+1)%2], -1, sizeof(dp[0]));
    }

    int ans = 0;

    for (auto& v : dp[(n-1)%2]) {
        for (auto& w : v) {
            for (auto& x : w) {
                for (auto& y : x) {
                    ans = max(ans, y);
                }
            }
        }
    }

    cout << ans;
    return 0;
}

/*
이건 어쩔까나.
단순히 DP로는 안 될 것 같은데?

dp[n][2][3]

---
어쩔때 다른 광산으로 보내야 할까?


---
음식 종류도 2종류 밖에 없다면?
다른 종류 나오면 1
같은거 나오면 2로 보내는 방식으로 하면 무조건 최대.

FBFB
FFFFFBBBBBFFB


---
3종류 라면?
FBF? -> 이렇게 2종류나 되는 거라면 1번에만 쌓는게 이득이지.
FBFF -> 이것도 이득이긴 하고
FBFFF -> 이건 2로 보내도 상관 없지.

FBFFFH 라는 문자열에서 최대값은
FBFH : 1 + 2 + 2 + 3
FF : 1 + 1
10.


FBFF : 1 2 2 2
FH : 1 2
10
흠 상관 없나


MBMFFB

MBMFFB : 1 2 2 3 2 2
12
흠;;;

---
9
MBBBBMMMB

MBBMMB : 1 2 2 2  2 2
BBB : 1 1 1
14

MBBBMMB
BMB

---
dp로 한다네.

dp[i][j][k][l] : 1번 광산에서 3번째 2번째 음식이 i, j고, 2번째 광산에선 k, l일 때
*/