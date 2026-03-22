#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

vector<bool> sieve(1100100, false);
vector<LL> primes;

void GetPrimes() {
    for (LL i = 2; i < 1100100; i++) {
        if (sieve[i]) continue;
        
        primes.push_back(i);

        for (LL k = i * i; k < 1100100; k += i) sieve[k] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    GetPrimes();

    LL n, m;
    cin >> n >> m;

    unordered_set<LL> chk;
    for (auto& p : primes) {
        LL d = p*p;

        for (LL i = (n + d - 1) / d * d; i <= m; i += d) chk.insert(i);
    }

    cout << m - n + 1 - chk.size();


    return 0;
}

/*
(max까지 제곱 ㄴㄴ 수 개수) - ((min-1)까지 제곱 ㄴㄴ 수 개수)
하면 될 것 같은데

최대 개수 1백만이면 그냥 브포하면 되나.

제곱 ㄴㄴ인지 O(sqrt(n))보다 빠르게 구해야 해.

소수의 제곱수만으로 보는 건? ㄴㄴ 소수 개수가 좀 되네.

한 수마다 하지 말고 다른 방식.
제곱수로 나누면... 흠.

에테체처럼 세기?

*/