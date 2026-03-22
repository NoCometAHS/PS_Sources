#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ans = -1;
    for (int i = n - 1; i >= 2; i--) {
        if (arr[i] < arr[i-1] + arr[i-2]) {
            ans = arr[i] + arr[i-1] + arr[i-2];
            break;
        }
    }

    cout << ans;

    return 0;
}

/*
삼각형 조건
a + b > c

큰거부터 찾으면 금방 찾을 것 같기도 하고.

O(n^2) 보다 빠르게 찾기.

빗변이 정해졌다고 했을 때,
나머지 두변의 합의 최대는 정해져 있어.
= c - 1

c 이전에 있는 수열에서
최소 최대의 합이 c - 1 이하라면, 그 안에 정답이 있는건가.

아니지
그냥 최대 최대 합을 봐야 하잖아.

*/