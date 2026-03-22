#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    int n;
    scanf("%d", &n);

    vector<iipair> arr(n);
    for (auto& [st, en] : arr) {
        int h, m;
        scanf("%d:%d", &h, &m);

        st = max(0, h*60 + m - 10);
        en = min(23*60+59, h*60 + m + 10);
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int curEn = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (curEn < arr[i].first || cnt >= 3) {
            ans++;
            cnt = 1;
            curEn = arr[i].second;
        }
        else {
            cnt++;
        }


    }

    cout << ans;
    return 0;
}
