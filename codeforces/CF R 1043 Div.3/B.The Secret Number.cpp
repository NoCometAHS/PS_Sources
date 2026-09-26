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
    
    while (tc--) {
        LL n;
        cin >> n;
        vector<LL> ans;

        for (LL i = 0; i < 18; i++) {
            LL d = 1 + mypow(10, i+1);          
            if (n % d != 0) continue;

            ans.push_back(n/d);
        }

        sort(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        for (auto& i : ans) cout << i << ' ';
        if (!ans.empty()) cout << '\n';
    }
    return 0;
}

/*
수 x.
양수 개의 0 오른족에 붙여서 y를 만듬.

n = x + x*10^m = x*(1+10^m)


n 이 주어졌을 때 가능한 x 다 출력해라.

18번 브포 해서 하면 될 것 같은데. -> 

*/