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
    arr.push_back(2e9);

    sort(arr.begin(), arr.end());


    while (qCnt--) {
        LL x, y;
        cin >> x >> y;

        LL s = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        LL lt = s, rt = n, mid;
        LL t = 0;
        while (lt <= rt) {
            mid = (lt + rt) / 2;

            if ((arr[mid] - x + 1) - (mid - s + 1) >= y) {
                t = mid;
                rt = mid - 1;
            }
            else {
                lt = mid + 1;
            }
        }
        cout << x + y - 1 + t - s << '\n';

    }
    return 0;
}

/*

Y < (A_t - x + 1) - (t - s  + 1);


ans < A_t

ans = x + (y - 1) + (t - s)

*/