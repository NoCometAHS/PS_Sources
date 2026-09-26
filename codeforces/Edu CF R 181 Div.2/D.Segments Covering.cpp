#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

constexpr LL MOD = 998244353;

vector<iipair> arr[220202];
LL dp[220202];

LL dfs(LL cur, LL end) {
    if (dp[cur] != -1) return dp[cur];
    if (cur == end) return 1;

    LL ret = 0;
    for (auto [to, p] : arr[cur]) {
        if (arr[to].empty()) continue;

        ret += dfs(to, end) * p % MOD;
        ret %= MOD;
    }

    return dp[cur] = ret;
}

LL modPow(LL a, LL b) {
    if (b == 0) return 1;

    LL ret = modPow(a, b/2);
    ret = ret * ret  % MOD;

    if (b % 2) {
        return ret * a % MOD;
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(dp, dp+220202, -1);

    LL n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        LL l, r, p, q;
        cin >> l >> r >> p >> q;
        arr[l].push_back({r+1, p*modPow(q, MOD-2)});
    }

    cout << dfs(1, m+1);
    return 0;
}

/*
no submit
*/

/*
m 길이의 m개로 등분된 선.

세그먼트 주어짐 l,r,p,q로 정의되는.
l, r범위를 포함하여 p/q의 확률로 존재한다.

각 부분이 한 세그먼트에만 포함될 확률은?

998244353(=MOD)의 모둘러의 역원을 이용해서 나누기 해라.
즉 나누는 수가 y라면 y^(mod-2)을 곱해라.

------
세그먼트 개수가 넘 많아서 브포는 불가능. -> 하나씩 본다고 하면 O(n)이다.

재귀에 dp 쓰면 될 것 같은데. 그렇게 모든 세그먼트를 한번씩만 보게 만들면.


*/