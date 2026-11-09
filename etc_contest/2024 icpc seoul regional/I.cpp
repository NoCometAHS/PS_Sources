#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> upper, lower, mid;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (y == 9999) {
            upper.push_back(x);
        }
        else if (y == -9999) {
            lower.push_back(x);
        }
        else {
            mid.push_back(x);
        }
    }


    sort(upper.begin(), upper.end());
    sort(lower.begin(), lower.end());
    sort(mid.begin(), mid.end());


    vector<iipair> upperRange, lowerRange;

    ll st, en;
    ll ans = 0;
    if (!upper.empty()) {
        st= upper.front(), en = upper.front();

        for (int i = 1; i < upper.size(); i++) {
            if (upper[i] - st > 10000) {
                upperRange.emplace_back(st, en);
                en = st = upper[i];
                ans++;
            }
            else {
                en = upper[i];
            }
        }
        upperRange.emplace_back(st, en);
        ans++;
    }

    if (!lower.empty()) {
        st = lower.front(), en = lower.front();
        for (int i = 1; i < lower.size(); i++) {
            if (lower[i] - st > 10000) {
                lowerRange.emplace_back(st, en);
                en = st = lower[i];
                ans++;
            }
            else {
                en = lower[i];
            }
        }
        lowerRange.emplace_back(st, en);
        ans++;
    }

    
    for (auto& x_ : mid) {
        iipair x(x_, x_);

        bool flag = true;
        int pos = lower_bound(upperRange.begin(), upperRange.begin(), x) - upperRange.begin();

        if (pos < upperRange.size() and upperRange[pos].first == x_) flag = false;

        if (pos + 1 < upperRange.size()) {
            if (upperRange[pos+1].second  - x_ <= 10000) flag = false;
        }
        if (pos - 1 >= 0) {
            if (x_ - upperRange[pos-1].first <= 10000) flag = false;
        }
        
        pos = lower_bound(lowerRange.begin(), lowerRange.begin(), x) - lowerRange.begin();

        if (pos < lowerRange.size() and lowerRange[pos].first == x_) flag = false;
        
        if (pos + 1 < lowerRange.size()) {
            if (lowerRange[pos+1].second  - x_ <= 10000) flag = false;
        }
        if (pos - 1 >= 0) {
            if (x_ - lowerRange[pos-1].first <= 10000) flag = false;
        }

        ans += flag;
    }

    cout << ans;
    return 0;
}