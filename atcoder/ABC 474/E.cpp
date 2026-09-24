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
        int n;
        cin >> n;

        LL mn = 1e9, base = 0;
        vector<LL> diff;

        for (int i = 0; i < n; i++) {
            LL a, b;
            cin >> a >> b;

            mn = min(mn, a);
            base += a;

            diff.push_back(b - a);
        }

        sort(diff.begin(), diff.end());

        LL ans = base;
        for (int i = 1; i <= n; i++) {
            base += diff[i-1];
            ans = min(ans, base + max(2*i - n, 0) * mn);
        }

        cout << ans << '\n';
    }
    

    return 0;
}


// 정가에 사야지 쿠폰 하나 생김.
// 쿠폰 얻는 법은 가장 싼거 만 사서 얻는 다고 생각하면 안 됨. 쿠폰 얻어서 사는 게 더 비싸서 일반 물건 살 수도 있음.
/*
1. 가장 싼 물건 사서 쿠폰 1개.
2. Ai - Bi가 가장 큰 얘한테 쿠폰 가격으로 사기.
3. 모든 Bi에 가장 싼 물건 가격 더하기.
4. Ai - Bi가 큰 얘들로 B (쿠폰 개수 < 남은 물건 개수 까지만)
5. 남은 얘들 다 쿠폰 가로.

---
dp 느낌 나는데

dp[i][2] 
// i까지 사는데 최소 비용. 
// 마지막을 정가로 샀음. min(전의 할인가 + 현재 정가, 전의 정가 + 전의 정가)
// 마지막을 할인가로 샀음. min(전에 정가 + 현재 할인가, 가장싼 정가 + 현재 할인가)

이러면 사는데 순서가 부여되버리는 거 아닌가.
순서도 중요한데
가장 싼 물건 빼면 순서가 중요한가? 정가 순 정렬 하면 되는 거 아닌가.
전의 할인가 볼때 어짜피 정가가 싸야지 의미 있는거니깐?

정가로 다른 물건 여러개 샀을 때가 반영이 안 되는 것 같은데.

---
editorial

왜 쿠폰 쓰는 거면 무조건 싼 물건 사서 하는거지?
ㄴㄴ 그게 아님.

k개 만큼 쿠폰을 썼다고 한다면 N - k 개는 정가 구매.
필요한 쿠폰 개수는 k개.

k - (N - k) = 더 사야하는 쿠폰 개수

max(2k - N, 0)

쿠폰 주고 살 얘들이 결정되었다면, 정가 구매는 한 번에 하면 되니깐
이것 외에 순서는 의미 없어.

*/