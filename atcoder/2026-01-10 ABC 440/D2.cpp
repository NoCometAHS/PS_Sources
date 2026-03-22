#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, qCnt;
    cin >> n >> qCnt;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    while (qCnt--) {
        LL x, y;
        cin >> x >> y;

        LL lt = x, rt = 2e10, mid;
        LL ans = 2e9;
        while (lt <= rt) {
            mid = (lt + rt) / 2;
            
            LL cnt = upper_bound(arr.begin(), arr.end(), mid) - lower_bound(arr.begin(), arr.end(), x);

            

            if ((mid - x + 1) - cnt < y) {
                lt = mid + 1;
            }
            else {
                if ((mid - x + 1) - cnt == y) ans = min(mid, ans);
                rt = mid -1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

/*
이건 어디서 틀리게 될까?
*/