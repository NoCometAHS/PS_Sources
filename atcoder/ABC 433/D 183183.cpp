#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

LL modPow(LL n, LL p, LL m) {
    if (p == 0) return 1;

    LL ret = modPow(n ,p/2, m);
    ret = ret * ret % m;
    if (p % 2) {
        return ret * n % m;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n, m;
    cin >> n >> m;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    vector<unordered_map<int,int>> modRes(11);

    for (int i = 1; i <= 10; i++) {
        LL space = modPow(10, i, m);

        for (int k = 0; k < n; k++) {
            modRes[i][(arr[k] % m) * space % m]++;
        }
    }

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        LL dec = 0;
        for (LL num = arr[i]; num; num /= 10) dec++;
        LL t = m - arr[i] % m;
        if (t == m) t = 0;

        ans += modRes[dec][t];
    }
    
    cout << ans;

    return 0;
}

/*
n^2 풀이는 안 돼. (밋인미도 안 돼)

두 개를 합친다는 건
A[i]*10^p + A[j]를 한 다는 것.

더하는 두 수가 M으로 나누어 떨어지면? 더해도 나누어 떨어진다. -> 모듈러 법칙 ㅇㅇㅇ.

각 수에 10^p 한거 구하고 나눠봐.

*/