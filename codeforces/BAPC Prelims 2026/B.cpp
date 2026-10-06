#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;Q

    if (abs(n - m) > 1 || n + m > 9) {
        cout << "impossible";
        return 0;
    }

    int status[9] {0, 1, 0, 0, 1, 0, 1, 0 , 1}; //o is 0

    if (n > m) {
        for (auto& i : status) i = !i;
    }

    char ans[9];
    fill(ans, ans + 9, '.');

    while (n--) {
        for (int i = 0; i < 9; i++) {
            if (status[i] == 1) {
                ans[i] = 'X';
                status[i] = -1;
                break;
            }
        }
    }

    while (m--) {
        for (int i = 0; i < 9; i++) {
            if (status[i] == 0) {
                ans[i] = 'O';
                status[i] = -1;
                break;
            }
        }
    }


    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            cout << ans[i*3+k];
        }
        cout << '\n';
    }


    

    return 0;
}