#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

LL gcd(LL a, LL b) {
    if (b) return gcd(b, a % b);
    return a;
}

LL lcd(LL a, LL b) {
    LL t = gcd(a, b);
    return a / t * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        LL a, b;
        cin >> a >> b;

        while (a != 1) {
            LL x = (b + a - 1)/a;
            
            LL par = lcd(x, b), child = par / b * a;
            child -= par / x;

            a = child;
            b = par;
            
            LL g = gcd(a, b);
            a /= g, b /= g;
        }
        
        cout << b << '\n';
    }
    return 0;
}

/*
일단 x는
1 < x < b 일거야.
이분탐색으로 찾을 수 있을 듯?

시간 초과 ㄷㄷ.

결국 
a를 1로 만들어야 한다는건데

4/7 을 단위분수의 합으로 나타내야하고

---
1/x <= a/b

b/a <= x



*/
