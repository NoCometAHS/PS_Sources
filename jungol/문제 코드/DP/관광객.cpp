#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int dp[202][101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w;
    cin >> w >> h;
    
    TwoVector<int> arr(h, vector<int>(w));
    for (auto& v : arr) {
        for (auto& i : v) {
            char ch;
            cin >> ch;

            i = (ch == '.' ? 0 : (ch == '*' ? 1 : -1));
        }
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = arr[0][0];
    
    for (int step = 1; step < h + w - 1; step++) {
        for (int r1 = 0; r1 < h; r1++) {
            for (int r2 = 0; r2 < h; r2++) {
                int r1x = step - r1, r2x = step - r2;

                if (r1x < 0 || r2x < 0 || r1x >= w || r2x >= w || arr[r1][r1x] == -1 || arr[r2][r2x] == -1) continue;

                int gain = arr[r1][r1x] + arr[r2][r2x] - (arr[r2][r2x] == 1 && r1 == r2);

                for (auto& dr1 : {0, 1}) {
                    for (auto& dr2 : {0, 1}) {
                        if (r1 - dr1 < 0 || r2 - dr2 < 0) continue;
                        if (dp[step-1][r1-dr1][r2-dr2] < 0) continue;
                        
                        dp[step][r1][r2] = max(dp[step][r1][r2], dp[step-1][r1-dr1][r2-dr2] + gain);
                    }
                }
                
            }
        }
    }

    cout << dp[h+w-2][h-1][h-1];

    return 0;
}

/*
간단한 dp 안 됨.
예제 2에서 걸림.

flow?
이등 제어를 어떻게 하지? 내려가야 할 때랑 올라가야 할 때 구분이 되어야 하고.
유량이 공유되어야 함.

h*w = 10 000

일단 최대 (h+w-2)*2개가 먹을 수 있는 최대 (입출구 거는 먹고 시작한다고 했을 때.)
각 갈 때마다는 h+w-2개가 최대.

뭔가 dpdp?

dp[걸음수][갈 때 행번호][올 때 행 번호]
*/