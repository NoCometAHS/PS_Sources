#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL a, b;
    cin >> a >> b;

    int t = 1;
    while (a!= 0) {
        int ans = 0;
        for (LL i = 0; i*(i+1)/2 + 1 < b; i++) {
            LL x = i*(i+1)/2;
            if (x+1 <= a) continue;

            LL n = floor(sqrt(x+1));
            ans += n*n == x + 1;
        }

        cout << "Case " << t << ": " << ans << '\n';

        cin >> a >> b;
        t++;
    }
    return 0;
}

/*
x + 1 = m*m
x = n*(n+1)/2

n(n+1)/2 = m*m-1

n(n+1) = 2(m*m-1)

무조건 N(N+1)은 짝수고
그럼 중요한건 m*m-1 과 n(n+1)의 관계

n은 2(m^2 - 1)/(n+1)

m^2-1을 잡았을 때, 어떤 자연수로 나누어 떨어지기만 하면 된다는 건가.
-> n이 서로 다른 값이 되니깐 모순, 그니깐 이거 아님



n(n+1)/2 + 1이 거듭제곱이기만 하면 된다.

x= n(n+1)/2

*/