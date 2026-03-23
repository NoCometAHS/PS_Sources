#include "bits/stdc++.h"

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
*/