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

    int cur = 1;
    bool rev = false;
    while (n--) {
        string s;
        int c;
        cin >> s >> c;

        if (s.front() == 'H') {
            if (c != cur) {
                rev = !rev;
            }

            cout << cur << " NO\n";
        }
        else {
            cout << cur << (c == cur ? " YES" : " NO") << '\n';
        }

        if (rev) {
            cur = (cur + 10) % 12 + 1;
        }
        else {
            cur = cur % 12 + 1;
        }
    }

    return 0;
}
