#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        TwoVector<int> score(n, vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            int v, a, b;
            cin >> v >> a >> b;
            a--, b--;

            score[a][b] += v;
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        
        int mxScore = 0, cnt = 0;
        do {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                for (int k = i+1; k < n; k++) {
                    cur += score[order[i]][order[k]];
                }
            }

            if (mxScore < cur) {
                mxScore = cur;
                cnt = 1;
            }
            else if (mxScore == cur) {
                cnt++;
            }

        }while (next_permutation(order.begin(), order.end()));


        cout << mxScore << ' ' << cnt << '\n';
    }
    return 0;
}

/*

m개의 평가가 있어도
n이 9면

9*8 = 72 종류의 평가만 있는 거 아니냐.

*/