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
        int n, x;
        cin >> n >> x;

        vector<int> primeDivisor;
        for (int i = 2; i <= x; i++) {
            if (x % i) continue;

            while (x % i == 0) x /= i;
            
            primeDivisor.push_back(i);
        }

        vector<LL> arr(n);
        for (auto& i : arr) cin >> i;

        vector<LL> candi;
        for (auto& p : primeDivisor) {
            candi.push_back(0);

            for (auto& i : arr) {
                if (i % p) continue;

                candi.back() += i;
            }
        }

        LL ans = 0;
        for (auto& i : candi) {
            ans = max(ans, i);
        }

        cout << ans << '\n';

    }

    return 0;
}

/*
n개의 파일, 각각 ai개의 코인

ai > 0 and gcd(ai, x) != 1 인 i 선택. 없으면 멈춤.
gcd(ai, x) = g. 해당 파일에서 g개 가져옴.

x를 g로 바꾸고 반복.

최다 코인 먹게 해라.


x와 ai의 최대 공약수로 가져가네.

일단 어떤 것을 가져갔으면 가져간 것들끼리의 순서는 상관 없나? ㅇㅇ 없는 듯?
약수로 x인 ai가 있지 않은 이상 x는 점점 줄어들어.
뭔가의 약수합 같은 느낌이라.

최대로 가져갈 수 있는 코인은, x*n개.

각 ai마다 필요한 약수가 있어.

같은 파일에서 여러번 가져갈 수 있는 거 아니냐.
가져갈 수 있는 파일은 g*a로 쓸 수 있을거고.
지금 x는 g니깐 싹 가져가겠네?

그럼 이제 어떤걸 가져가는 가냐 문제내.
그리디? ㄴㄴ

dp 같은 느낌으로 해줘야 할 것 같은데.

dp[i][d] : i번쨰 ai까지 봤고, d번째 x의 소인수까지 봤을 때 최대값.
흠.

그냥 같은 소인수 있는 것들은 다 먹을 수 있는 거 아님?

x 2 * 3
a 2 * 7, 2 * 7, 3 * 1e9

라고 했을 때,
마지막 것만 선택했어야 했어.
이건 위같은 dp로 볼 수 있냐?

dp[i][d] = dp[i-1][d-1] + a[i] if a[i] % divisor[d] == 0
ㄴㄴㄴ 이걸로 못해.
d가 사라질지 안 사라질지 모르잖아.

x의 모든 약수에 대해서 볼까.

최대공약수인 ai를 각 약수 인덱스에다가 더해줘.

dp[d] : x가 x의 약수 d일 때 먹을 수 있는 최대 돈

걍 각 소인수로 남게 되었을 때 뭐 먹을 수 있는 지 다 더하고, max 취하면 되는 것 같은데.

*/