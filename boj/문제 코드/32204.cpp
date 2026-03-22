#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    TwoVector<LL> dp(2, vector<LL>(n, 0));
    dp[1][n-1] = dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i-1] > arr[i]) dp[0][i] = 1;
        else dp[0][i] = dp[0][i-1] + 1;
    }

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] < arr[i+1]) dp[1][i] = 1;
        else dp[1][i] = dp[1][i+1] + 1;
    }

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && arr[i-1] == arr[i]) {
            ans += dp[1][i];
            continue;
        }
        ans += dp[0][i] * dp[1][i];
    }

    arr.push_back(-1);

    cout << ans;

    return 0;
}

/*
같은 범위를 여러번 보는 문제가 발생.

이건 수가 같은 부분에서만 이루어지나? ㅇㅇ -> 아니네 그냥 반복 될 수 있네.

1 1 1 1
만들 수 있는 산 개수는
len * (len+1)/2

내코드에서 만들어지는 산 개수는
len * 1 + (len-1)*2 ... + 2 * (len-1) + len

자기 빼고 dp 하면 되나. ㄴㄴ


----
산의 꼭지점이 길면 문제가 생기네.

1개면 문제가 없어.
같은 꼭짓점끼리는 뱉어내는 개수도 같은 것 같은데? 자기 자신 빼고. 일부만 맞았어.

왼쪽에서 오른쪽으로 간다고 했을 때.
왼쪽 얘에선 오른쪽놈을 시작으로 한 산이 없어.
*/