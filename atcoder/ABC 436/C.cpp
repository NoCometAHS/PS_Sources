#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    set<iipair> chk;
    iipair delta[4] = {{0, 0},{1, 0},{0, 1},{1, 1}};

    int ans = 0;
    while (m--) {
        int r, c;
        cin >> r >> c;
        
        bool flag = true;
        for (int d = 0; d < 4; d++) {
            
            if (chk.count({r+delta[d].first, c +delta[d].second})) {
                flag = false;
                break;
            }
        }


        if (flag) {
            for (int d = 0; d < 4; d++) {
                chk.insert({r+delta[d].first, c +delta[d].second});
            }
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}


/*
각 블록들이 겹치는 지를 확인 해야 하네?

근데 n이 10억이라 직접은 못 해봐.
set에다 넣어버릴까?

*/