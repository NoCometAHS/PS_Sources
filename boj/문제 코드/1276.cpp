#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

struct platform{
    LL y;
    LL st;
    LL en;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<platform> arr(n);
    for (auto& [y, st, en] : arr) {
        cin >> y >> st >> en;
    }

    sort(arr.begin(), arr.end(), [](platform& a, platform& b) {
        return a.y < b.y;
    });


    LL ans = 0;
    for (int i = 0; i < n; i++) {
        auto [y, st, en] = arr[i];
        bool f1 = false, f2 = false;

        for (int k = i-1; k >= 0; k--) {
            if (arr[k].st <= st && st < arr[k].en)  {
                ans += y - arr[k].y;
                f1 = true;
                break;
            }
        }

        for (int k = i-1; k >= 0; k--) {
            if (arr[k].st < en && en <= arr[k].en)  {
                ans += y - arr[k].y;
                f2 = true;
                break;
            }
        }

        if (!f1) ans += y;
        if (!f2) ans += y;
    }

    cout << ans;

    return 0;
}

/*
플레폼에 걸쳐야지 기둥 밑에 플레폼 위에 기둥 설치 ㄱㄴ.
*/