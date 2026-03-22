#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, m;
    cin >> n >> m;

    LL mn = 1e9, sum = 0;
    for (int i = 0; i < n; i++) {
        for (int k=0, num; k < m; k++) {
            cin >> num;

            sum += num;
            mn = min<LL>(mn, num);
        }
    }

    cout << sum - mn;
    return 0;
}

/*
2칸씩 뺄 수는 있는데,
한 칸이 0이면 숫자 1만 뺄 수 있음.

이미 0이 있으면, 모든 칸의 수합이 답
0이 없으면, 모든 칸의 수 합 - 가장 작은 수

*/