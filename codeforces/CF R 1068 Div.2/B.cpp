#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL n;
        cin >> n;

        vector<LL> rc(n), bc(n);
        for (auto& i : rc) cin >> i;
        for (auto& i : bc) cin >> i;

        vector<iipair> dp(n, {-1e18, 1e18});
        dp[0].first = max(-rc[0], bc[0]);
        dp[0].second = min(-rc[0], bc[0]);

        for (int i = 1; i < n; i++) {
            dp[i].first = max(dp[i-1].first - rc[i], bc[i] - dp[i-1].second);
            dp[i].second = min(dp[i-1].second - rc[i], bc[i] - dp[i-1].first);
        }

        cout << dp.back().first << '\n';
    }
    return 0;
}

/*
점수는 초기 점수 0인 k로 표시됨.

n턴 i번째에 정수 a_i가 있는 레드카드, b_i가 있는 블루카드 받음.
둘중 하나만 골라서 점수 업데이트

- 레드카드는 지금 점수를 k - a_i로 만듬
- 블루카드는 지금 점수를 b_i - k로 만듬

최대 점수는?
---

일단 LL 써야 함.
a_i는 음수일 때면 점수를 a_i만큼 증가시켜줘
b_i는 k가 음수일 때면 점수를 -k*2 + b_i 만큼 증가시켜줘 

---
그냥 .dp로 모든 경우 보면 되는 거 아닌가?
전의 최선의 결과가 지금의 최선의 결과에 영향을 못 미치는 경우가 있어.
-100 -1
100 1000

dp[n][2]
-> dp[n][0]을 n번째 카드를 골랐을 때 최대값
-> dp[n][1]을 " 최저값
이라고 한다면?

만약 블루 카드를 고른다고 한다면, 전까지의 값에서 최저값일때 쓰는 게 좋잖아.
레드카드는 최대값이라고 했을 때가 좋고.
*/