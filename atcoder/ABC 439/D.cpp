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

    map<LL, vector<LL>> mul3, mul5, mul7;

    for (int i = 0; i < n; i++) {
        LL num;
        cin >> num;

        if (num % 7 == 0) mul7[num/7].push_back(i);
        if (num % 5 == 0) mul5[num/5].push_back(i);
        if (num % 3 == 0) mul3[num/3].push_back(i);
    }

    LL ans = 0;
    for (auto& [mul, v] : mul5) {
        for (int j : v) {
            LL res1 = lower_bound(mul3[mul].begin(), mul3[mul].end(), j) - mul3[mul].begin();
            LL res2 = lower_bound(mul7[mul].begin(), mul7[mul].end(), j) - mul7[mul].begin();
            
            ans += res1 * res2;

            res1 =  mul3[mul].end() - upper_bound(mul3[mul].begin(), mul3[mul].end(), j);
            res2 =  mul7[mul].end() - upper_bound(mul7[mul].begin(), mul7[mul].end(), j);

            ans += res1 * res2;
        }
    }

    cout << ans;

    return 0;
}

/*
길이 n인 자연수 수열 

밑의 조건을 만족하는 (i, j, k) 쌍의 개수를 찾아라

a[i] : a[j] : a[k] = 7:5:3

min(i,j,k) = j || max(i,j,k) = j

---
자연수열이니깐
a[j]는 5의 배수일 수밖에 없어.
a[i], a[k]도 각각 7, 3의 배수.


*/