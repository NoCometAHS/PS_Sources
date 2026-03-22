#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL a, b;
        cin >> a >> b;

        int ans = 0;
        for (LL i = 1, x = a, y = b; true; i *= 2) {
            if (x - i >= 0) {
                ans++;
                x -= i;
            }
            else {
                break;
            }

            i *= 2;

            if (y - i >= 0) {
                ans++;
                y -= i;
            }
            else {
                break;
            }
        }

        int ret = 0;
        for (LL i = 1, x = b, y = a; true; i *= 2) {
            if (x - i >= 0) {
                ret++;
                x -= i;
            }
            else {
                break;
            }

            i *= 2;

            if (y - i >= 0) {
                ret++;
                y -= i;
            }
            else {
                break;
            }
        }

        cout << max(ret, ans) << '\n';
    }
    return 0;
}

/*

1개 이상의 레이어
맨 위의 레이어 크기 1
밑에는 2
.. 2배씩 커짐

크기가 k면 k킬로그램의 초콜릿 필요
퐁당 퐁당 색
*/