#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, m;
    cin >> n >> m;

    vector<LL> s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    LL a, d;
    cin >> a >> d;

    n += d-1;
    s.resize(n+1, 0);

    TwoVector<LL> dp(n+1, vector<LL>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i-1] + s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int k = d; k <= n; k++) {
            dp[i][k] = max(dp[i-1][k-d] + a, dp[i][k-1] + s[k]);
        }
    }

    int ans = -1;
    for (int i = 0; i <= n; i++) {
        if (dp[i].back() >= m) {
            ans = i;
            break;
        }
    }


    cout << ans;

    return 0;
}

/*
m점 이상

n일
s_i 점 얻음.

헌혈 하면 A점
    단, 점수 얻고 D일간 뭐 못함

헌혈을 적게 해서 M점 이상 모으기.
최소 헌혈 횟수.

---
일단 봉사 활동만 해서 점수 모아봐.
    채워지면 답은 0
    안 채워지면?
        헌혈 해야 함.
        i일에 헌혈 해서 얻는 점수는 (A - s_(i ~ i+d-1)의 점수합)

        방법 1.
            얻는 점수가 최대인 것들만 뽑아서 만든다
        
        1 반례.
            a b c d e f g h
            가 있을 때, c d e f 에 뽑는 게 최대 점수를 얻지만
            a b c d, e f g h 를 뽑아야 M 점을 넘는다.
            
            2 2 1 1 1 1 2 2
            20 4
        
        방법 2.
            dp?
            dp[i] : i날을 끝으로 얻을 수 있는 최고 점수
            dp[i] = dp[i-1] + s[i], dp[i - d] + A

            되는지만 확인 했지 헌혈 횟수는 생각 못 했네 ㅋㅋ.

            dp[n][i] : n번 헌혈 했지만, i날까지 했을 때 점수 최댓값
            dp[n][i] = dp[n-1][i-d] + a, dp[n][i-1] + s[i];

            이러면 헌혈 하기 전에 쉬는게 되 버리네.
            dp[n][i] = dp[n-1][i-d] + a, dp[n][i-1] + s[i];
            다르게 생각하면 i - d + 1일에 헌혈 한거야.

            1 4 8 6 3 0 


*/