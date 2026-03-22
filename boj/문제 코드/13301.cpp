#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<LL> fibo(81, 0);
    fibo[1] = fibo[2] = 1;
    for (int i = 3; i < 81; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    
    int n;
    cin >> n;

    if (n == 1) cout << 4;
    else {
        cout << fibo[n]*2 + (fibo[n]+fibo[n-1])*2;
    }
    return 0;
}

