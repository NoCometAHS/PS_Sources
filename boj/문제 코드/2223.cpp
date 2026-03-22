#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, x, monster;
    cin >> t >> x >> monster;

    int mnMove = 1e9;
    while (monster--) {
        int d, s;
        cin >> d >> s;

        mnMove = min(mnMove, (d+s-1) / s);
    }

    if (mnMove <= 1) {
        cout << 0;
    }
    else if (t < mnMove) {
        cout << t * x;
    }
    else {
        cout << (t-(mnMove-1))/2 * x + (mnMove-1) * x;
    }
    return 0;
}

/*
가장 빨리 내게 다가올 수 있는 얘만 보면 되는 거 아니냐.

m번만에 다가옴
n번만에 다가옴

n < m 일 때,
n-1 줍고
n-1번 기다리길 반복하면 되는 거 아니냐

m번 다가오는 얘가 다가 올 수가 없잖아.
마지막 떠나기 직전에 막 챙긴다 해도. n만 안 넘으면 m인 애가 어떻게 와.

그냥 1번 챙기고 1번 쉬고 하면 되는 거 아님?
3번 연속으로 챙기고, 3번 연속으로 쉬나 뭔 차이야.

1번 챙기고 쉬고를 반복하다가 가기 직전에 연속으로 챙기면 될 듯?

*/