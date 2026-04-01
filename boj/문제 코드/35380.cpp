#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        if (n == 1) {
            cout << 1 << '\n';
        }
        else if (k != 2) {
            cout << -1 <<'\n';
        }
        else {
            cout << 2 << ' ';
            for (int i = 0; i < n-2; i++) {
                cout << 3 + i << ' ';
            }
            cout << 1 << '\n';
        }
    }
    
    return 0;
}

/*
1 2 3 4 5
3 1 3 4 2


2 1 3 4 5
2 3 4 5 1


P_1 = 2
P_{2} = P_2
P_{P_2} = P_3
P_{P_3} = P_4

P_1 = 3
P_{3} = P_2
P_{P_3} = P_3

*/