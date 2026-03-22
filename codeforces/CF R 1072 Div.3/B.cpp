#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL s , k, m;
        cin >> s >> k >> m;

        LL cnt = m/k, left;

        if (cnt % 2) {
            left = min(k, s);
        }
        else {
            left = s;
        }

        left = max(0LL, left - m % k);

        cout << left << '\n';
    }
    return 0;
}

/*
모래 시계 s 분짜리, 
뒤집으면 시작, 딱 k분 마다 다시 뒤집어
m분 안에 떠냐야 해.

떠난 뒤로 얼마나 모래가 지속될까

floor(m/k)번 뒤집어.

s-k 분 남았다가 뒤집으면 k분
2번째 뒤집으면 s분


*/