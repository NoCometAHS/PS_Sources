#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

LL gcd(LL a, LL b) {
    if (b) return gcd(b, a % b);
    return a;
}

LL lcd(LL a, LL b) {
    return a / gcd(a, b) * b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<LL> arr(n);
    LL lt = 0, rt = 1;
    for (auto& i : arr) {
        cin >> i;
    }


    LL ans = arr.back();
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] < ans) {
            ans = ((ans + arr[i] - 1) / arr[i]) * arr[i];
        }
        else {
            ans = arr[i];
        }
    }

    cout << ans;


    
    
    return 0;
}

/*
양의 정수배로도 ㄱㄴ

최소 공배수?
    일단 v의 최대값보단 커야하고..
    모든 v로 나뉠 수 있어야 함.

    가는 중에 속도를 떨굴 수 있어서 최소 공배수보다 작아질 수 있어.

이분 탐색?
    성립하는 최소값 x가 있을 때, 
    x의 이후로는 전부 가능하고
    x의 이전으로는 불가능

    처음 rt가 너무 클 수 있는 것 같은데
    v가 1e9에 가까운 소수라면 그 값의 최소 공배수도 ll 범위를 넘잖아.

dp?
    dp[i] : i ~ n 까지의 행성을 갈 때 필요한 최소 값.

    dp[n] = v[n];
    dp[i] = 
    v[i] < dp[i+1] :dp[i+1] 보다 큰 최소의 v[i] * x
    v[i] >= dp[i+1] : v[i]

*/