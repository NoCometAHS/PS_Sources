#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<string> nums(n);
    for (auto& i : nums) cin >> i;

    int mod;
    cin >> mod;

    vector<int> tenMod(55);
    tenMod[0] = 1;
    for (int i = 1; i < 55; i++) {
        tenMod[i] = tenMod[i-1] * 10 % mod;
    }


    vector<iipair> arr;
    for (auto& s : nums) {
        int res = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            res += (s[i]-'0') * tenMod[s.length()-1 - i];
            res %= mod;
        }
        arr.emplace_back(res, tenMod[s.length()]);
    }

    vector<vector<LL>> dp(1 << n, vector<LL>(mod, 0));
    for (int i = 0; i < n; i++) {
        dp[1 << i][arr[i].first] += 1; 
    }

    for (int s = 1; s < (1 << n); s++) {
        for (int v = 0; v < mod; v++) {
            for (int i = 0; i < n; i++) {
                if (s & (1 << i)) continue;
                int nextState = s | (1 << i), nextMod = (v * arr[i].second + arr[i].first) % mod;
                dp[nextState][nextMod] += dp[s][v];
            }
        }
    }

    LL par = 1, child = dp[(1 << n) - 1][0];
    for (int i = 1; i <= n; i++) par *= i;

    LL d = gcd(par, child);
    cout << child / d << "/" << par / d;


    return 0;
}

/*
순열을 다 보는 건 안 됨.
mod도 100보다 작은 건 뭐 떄문이지.

bit dp 쪽이니깐 어떻게 풀 수 있을 지 생각해보자.
수 길이가 이상하네 ㅋㅋ. 나머지로 다 처리 해야하나?

어떤걸 비트 상태로 표현 할 수 있을까.
아까 했던것처럼?

dp[사용한 숫자들][맨 뒤에 붙인 숫자] = k로 나누어 떨어지는 경우의 수

앞에 숫자가 어떻게 된 지를 알아야 더 붙이든 하는 거 아니냐.
게다가 앞에 붙인 숫자가 뭔지에 따라 되고 안 되고가 갈리는 거 아닌가.

100보다 작으니깐
dp[사용한 숫자들][그 전에 붙인 숫자][맨 뒤에 붙인 숫자] 이렇게 해버리면 되는 거 아니냐. 어짜피 2자리수로 갈리는 거 아님?

dp[s][u][v] += dp[s & ~(u) & ~(v)][i][j]
2^15 * 15 * 15 * 15 * 15
너무 큰데?

어짜피 합이니깐 어디에 하나로 합쳐 놓을까 했는 데 상관 없는 거 아닌가 ㄴㄴ
이거 애초에 더 앞에 값도 필요한데? 102 % 3 == 0

앞에 값도 최대 2자리, 뒤에 값도 최대 2자리 인걸 이용할 수 있나?

dp[사용한 숫자들][그 전에 붙인 모든 숫자에 mod 취한 거][맨 뒤에 붙인 숫자]

맨 뒤에 붙인 숫자의 원래 자리수를 가지고 있어야 함.
dp[s][u][v]
라고 했을 때

u * tenMod(v의 원래 자리수) + v 를 해야 함.

dp[s][v] 라고만 써도 될 것 같은데?
dp[사용한 숫자들][mod 취한 결과]

dp[s][v] = sum(dp[s & ~(1 << i)][u], 단, u와 i 번째 수를 합친 값에 % 7의 결과가 v)

다 돌아보는게 아니라 필요한 부분만 전파하는 느낌으로?

dp[s | (1 << i)][(u + i번째 수)%mod] += dp[s][u]
리프부터 더해보고 넣고를 반복하면?

2^15 * 100 * 15
로 끝나는 거 아니냐.
*/