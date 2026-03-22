#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double a, b, c;
    cin >> a >> b >> c;

    b /= 100, c /= 100;

    double fail = 1, sum = 0;
    while (b <= 1) {
        sum += fail;
        fail *= 1 - b;
        b += b * c;
    }
    cout << fixed;
    cout.precision(9);
    cout << a * (sum + fail);

    return 0;
}

/*
기댓값?
확률변수 * 확률 의 합
*/