#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;


int dp[21][21][40400];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int sum = 0;
    TwoVector<int> arr(n, vector<int>(n));
    for (auto& v : arr) {
        for (auto& i : v) {
            cin >> i;
            sum += i;
        }
    }



    TwoVector<int> items(n, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int k = 0; k < n; k++) {
            sum += arr[n-k-1][i];
            items[i][k+1] = sum;
        }
    }



    dp[0][0][0] = 1;

    for (int col = 0; col < n; col++) {
        for (int item = 0; item <= n; item++) {
            for (int i = 0; i <= item; i++) {
                for (int k = items[col][item]; k < 40400; k++) {
                    // if (dp[col%2][i][k - items[col][item]] == 0) continue;

                    dp[col+1][item][k] |= dp[col][i][k - items[col][item]];
                }
            }
        }
    }


    int ans = 1e9;
    int val, h;
    for (int i = 0; i <= n; i++) {
        for (int k = 0; k < 40400; k++) {
            if (dp[n][i][k] == 0) continue;
            int diff = abs(sum - k*2);

            if (diff < ans) {
                ans = diff;
                val = k;
                h = i;
            }
        }
    }

    cout << ans << '\n';

    vector<int> route;
    for (int i = n; i > 0; i--) {
        route.push_back(h);

        val -= items[i-1][h];

        
        while (h >= 0 && dp[i - 1][h][val] == 0) h--;
    }

    for (auto it = route.rbegin(); it != route.rend(); it++) {
        cout << *it << ' ';
    }

    return 0;
}

/*
그냥 임의의 칸 선택 문제면
단순히 냅색으로 충분함.

열에 있는 애들 바닥에서 부터 연속하게 선택해야 한다면?
dp 배열이 2개만 있음 된다.
지금, 이후
dp[2][100 * 400 + 1]

dp[2][h][100 * 400 + 1]

20 * 20 * 20 * 40000
*/