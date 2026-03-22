#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<LL>>;

    
LL n, CurDollar;

bool func(LL test, vector<vector<LL>>& arr) {
    LL usedDollar = 0;

    for (int i = 0; i < n; i++) {
        LL needed = arr[i][0] * test - arr[i][1];
        if (needed <= 0) continue;

        LL minCost = 1e18;
        for (int k = 0; arr[i][4]*k <= needed + arr[i][4]; k++) {
            LL t = needed - arr[i][4]*k;
            LL sc = (t + arr[i][2]-1)/arr[i][2];
            if (sc < 0) sc = 0;

            LL cost = arr[i][3] * sc + arr[i][5] * k;
            
            minCost = min(minCost, cost);
        }

        usedDollar += minCost;
    }

    return usedDollar <= CurDollar;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> CurDollar;

    vector<vector<LL>> arr(n, vector<LL>(6));
    for (auto& v : arr) {
        for (auto& i : v) cin >> i;
    }

    LL lt = 0, rt = 1, mid = 0, ans;
    while (func(rt, arr)) rt *= 2;

    while (lt <= rt) {
        mid = (lt + rt) / 2;

        if (func(mid, arr)) {
            ans = mid;
            lt = mid + 1;
        }
        else {
            rt = mid - 1;
        }
    }
    
    cout << ans;

    return 0;
}

/*
일단 필요할 때마다 작은 거로 사.
나중에 보니깐 작은거 여러개 산 것보다 큰거 하나 사는게 낫네, 그럼 전의 구매를 그렇게 교체.
Sum(Sm) <= Sv and Sum(Pm) >= Pv 일때 바꾸기.

안 되는 구만;

이분탐색이라네
*/
