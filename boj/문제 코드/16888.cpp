#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> move;
    for (int i = 1; i*i <= 1000000; i++) {
        move.push_back(i*i);
    }

    vector<bool> dp(1101010, false);

    for (int i = 1; i < 1101010; i++) {
        bool f = false;

        for (int k = 0; k < move.size() && move[k] <= i; k++) {
            if (!dp[i - move[k]]) {
                f = true;
                break;
            }
        }

        dp[i] = f;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        if (dp[n]) {
            cout << "koosaga\n";
        }
        else {
            cout << "cubelover\n";
        }
    }
    return 0;
}

/*
1, 4, 9 ...
으로 뺄 수 있어.

*/