#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans = 1;
    bool f = false;
    if (a % 2) f = ans *= a;
    if (b % 2) f = ans *= b;
    if (c % 2) f = ans *= c;

    if (f) cout << ans;
    else cout << a * b * c;


    return 0;
}

// 홀수가 있다면 무조건 모든 홀수의 곱
// 짝수만 있다면 모든 짝수의 곱