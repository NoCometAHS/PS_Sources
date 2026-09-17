#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, k, x;
    cin >> n >> k >> x;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<>());

    vector<LL> sake;
    LL sakeSum = 0;

    for (int i = 0; i < k; i++) {
        sake.push_back(arr.back());
        sakeSum += arr.back();

        arr.pop_back();
    }


    if (sakeSum < x) {
        cout << -1;
    }
    else {
        LL ans = n - k;

        int idx = 0;
        while (x > 0) {
            ans++;
            x -= sake.back();
            sake.pop_back();
        }

        cout << ans;
    }

    return 0;
}

/*
어떤 컵에 사케가 들어있든간에

x미리 리터의 사케를 마실수 있는
선택 횟수는?

일단 모든 일반 물들은 마시고
사케를 마신다고 생각하자


얘가 항상 많은 걸 선택한다고 하면?
그러면 사케를 큰 것부터 마실 수 있겠네?

*/