#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

LL mypow(LL a, LL b) {
    LL ret = 1;
    for (LL i = 0; i < b; i++) ret *= a;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    LL costs[20];
    for (int i = 0; i < 20; i++) {
        costs[i] = mypow(3, i+1) + i * mypow(3, i-1);
    }

    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<int> res;
        while (n) {
            res.push_back(n % 3);
            n /= 3;
            m -= res.back();
        }
        

        if (m < 0) {
            cout << -1 << '\n';
            continue;
        }

        while (res.size() > 1 && m >= 2) {
            int canDiv = m / 2;
            int doDivCnt = min(canDiv, res.back());

            auto it = res.end();
            it--; it--;
            *it += 3*doDivCnt;

            res.back() -= doDivCnt;
            m -= 2*doDivCnt;
            
            if (res.back() == 0) res.pop_back();
        }

        LL ans = 0;
        for (int i = 0; i < res.size(); i++) {
            ans += costs[i] * res[i];
        }
        
        cout << ans << '\n';
    } 
    return 0;
}


/*
c 하드 버전.

최소의 거래 횟수가 아니라 m번 이하면 ok.

비용만 최소로 해보면 될 것 같은데.

----------

x의 수박을 사는데, x-1의 수박을 3번 사면 똑같아.
큰 x에서 x-1 수박 사는 게 이득이야.

*/