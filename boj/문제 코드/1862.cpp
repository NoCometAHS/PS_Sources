#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int f(int n) {
    if (n <= 9) {
        if (n > 4) {
            return n-1;
        }
        return n;
    }

    int ret = f(n / 10);

    return ret * 10 + n % 10 - ret - (n % 10 > 4);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    cout << f(n);

    return 0;
}

/*
4 가 표현 될 때 마다, 해당 자릿값을 빼면 될 것 같은데.

맨 앞자리부터 시작해서

*/