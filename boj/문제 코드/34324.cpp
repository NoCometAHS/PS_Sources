#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<string> arr(n);
    for (auto& s : arr) {
        cin >> s;

        s.resize(1000, 0);
    }

    int ans = 0;
    for (int x = 0, y = 0; y < n; y++) {
        string res;

        int curX = x, curY = y;
        while (curX < 1000 && curY >= 0) {
            if (arr[curY][curX]) res += arr[curY][curX];
            curX++, curY--;
        }
        
        int idx = 0, cnt1 = 0, cnt2 = 0;
        while ((idx = res.find("KUMOH", idx)) != string::npos) {
            cnt1++;
            idx++;
        }

        reverse(res.begin(), res.end());

        idx = 0;
        while ((idx = res.find("KUMOH", idx)) != string::npos) {
            cnt2++;
            idx++;
        }

        ans += max(cnt1, cnt2);
    }

    for (int x = 1, y = n-1; x < 1000; x++) {
        string res;

        int curX = x, curY = y;
        while (curX < 1000 && curY >= 0) {
            if (arr[curY][curX]) res += arr[curY][curX];
            curX++, curY--;
        }

        int idx = 0, cnt1 = 0, cnt2 = 0;
        while ((idx = res.find("KUMOH", idx)) != string::npos) {
            cnt1++;
            idx++;
        }

        reverse(res.begin(), res.end());

        idx = 0;
        while ((idx = res.find("KUMOH", idx)) != string::npos) {
            cnt2++;
            idx++;
        }

        ans += max(cnt1, cnt2);
    }

    cout << ans;

    return 0;
}
