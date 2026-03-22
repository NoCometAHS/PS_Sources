#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> arr;
    int pre;
    cin >> pre;

    int d = 0;
    for (int i = 1; i < n; i++) {
        int cur;
        cin >> cur;
        
        arr.push_back(cur - pre);
        d = gcd(arr.back(), d);

        pre = cur;
    }


    int ans = 0;
    for (auto& i : arr) {
        ans += i / d - 1;
    }

    cout << ans;
    return 0;
}

/*
최대 n-1개를 심을 수 있어.
ㄴㄴ 더 심어야 할 수도 있어.

답에서 나무 간격은
나무 위치가 정수야 하니
각 간격들간의 최대 공약수 아니냐.

*/