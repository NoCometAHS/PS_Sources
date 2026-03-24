#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL, LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> primes;
    vector<int> sieve(5050, 0);
    for (int i = 2; i < 5050; i++) {
        if (sieve[i]) continue;

        primes.push_back(i);

        for (LL k = i; k < 5050; k += i) {
            sieve[k] = i;
        }
    }

    vector<map<int,int>> factors(5050);
    factors[2].emplace(2,1);
    for (int i = 3; i < 5050; i++) {
        factors[i] = factors[i-1];

        for (int num = i; num > 1; num /= sieve[num]) {
            factors[i][sieve[num]]++;
        }
    }

    auto getComb = [&](int r, int c) {
        map<int, int> res = factors[r];

        for (auto& [k,v] : factors[c]) res[k]-=v;
        for (auto& [k,v] : factors[r-c]) res[k]-=v;

        return move(res);
    };

    int tc;
    cin >> tc;

    while (tc--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        map<int, int> res1(getComb(a,b)), res2(getComb(c,d));
        bool ans = true;
        for (auto& [k, v] : res1) {
            if (v == 0) continue;
            ans &= res2[k] == 0;
        }

        cout << ans << "\n";
    }
    
    return 0;
}

/*
5000 * 5000 을 채우는 건 쉬운데,
수가 너무 크다.

뭔가 모듈러 법칙을 적용해서 숫자를 작게 만들 수 있을까.

서로소란?

gcd(a, b) == 1
= gcd(b, a % b)
ax + by = 1 의 해가 존재.

---
에테체를 어디에 씀?

C(n1, r1) % C(n2, r2) = C(n1, r1) -  C(n2, r2) * a 

n!을 소인수분해하고 열심히 구현 하는 거라고 하네.
*/