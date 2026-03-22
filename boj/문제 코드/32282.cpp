#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, c;
    cin >> n >> m >> c;

    double d = sqrt(n*n + m*m);

    if (d != 0 && d < c) {
        cout << 2;
    }
    else {
        cout << (int)ceil(d / c);
    }

    return 0;
}

/*
원의 둘레로만 이동할 수 있구나.

뭔가 삼각형 모양으로 만나는데
*/