#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    vector<iipair> arr;
    for (int i = 0; i < 3; i++) {
        int lt, rt;
        cin >> lt >> rt;

        arr.emplace_back(lt, 1);
        arr.emplace_back(rt, -1);
    }

    sort(arr.begin(), arr.end());

    int cur = 0, cnt = 0, ans = 0;
    for (auto& [t, v] : arr) {
        if (cnt == 1) {
            ans += (t - cur )*a;
        }
        else if (cnt == 2) {
            ans += (t - cur )*b * 2;
        }
        else if (cnt == 3){
            ans += (t - cur)*c * 3;
        }

        cur = t;
        cnt += v;
    }

    cout << ans;
    
    return 0;
}

/*


*/