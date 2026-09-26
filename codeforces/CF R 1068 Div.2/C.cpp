#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL n, m;
        cin >> n >> m;

        vector<LL> arr(n);
        for (auto& i : arr) cin >> i;

        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        vector<bool> chk(arr.size(), false);
        vector<LL> ans;
        
        bool canMake = true;
        for (int i = 0; i < arr.size(); i++) {
            if (chk[i]) continue;

            chk[i] = true;
            ans.push_back(arr[i]);

            for (LL cur = arr[i]*2; cur <= m; cur += arr[i]) {
                auto res = lower_bound(arr.begin(), arr.end(), cur);

                if (res == arr.end() || *res != cur) {
                    canMake = false;
                    break;
                }

                chk[res - arr.begin()] = true;
            }
        }

        if (canMake) {
            cout << ans.size() << '\n';
            for (auto& i : ans) cout << i << ' ';
        }
        else cout << -1;

        cout << '\n';
    }
    return 0;
}

/*
정수 n, k
길이 n 배열 a는 [1,k]의 값만 가지고 있음.

m개의 원소가 [1, k]의 값을 가지는 정수 집합 b, 다음 조건을 만족하면 완전하다.\

[1, n]인 각각의 i에 대해, a_i의 약수중 하나가 b에 있다.
[1, m]인 각각의 j에 대해, k이하의 b_j의 모든 양의 배수가 a에 한 번 씩은 있다.

가장 작은 사이즈의 b를 찾거나, 그런게 없다는 것을 밝혀라.

---
일단 안전 LL

첫번째 조건에 대해, 공약수면 b의 크기를 줄일 수 있지 않을까?
두번째 조건을 위해서, ai의 

일단 b의 원소는 a안의 원소로 이루어져야 해.
-> a_i에 없는 값이 b의 원소면, 1 곱했을 때 그 수가 없잖아.

그렇다면 a에서 가장 작은 수는 무조건 b에 들어가야 해.
-> 그렇지 않으면 그 수의 약수를 b에 넣을 수 없으니깐.

그 때! 그 작은 수의 k이 이하인 모든 배수가 a안에 있어야 해!
-> 안 그러면 모든 양의 배수가 a에 들어가 있지 않은거니깐.

브루트 포스로 O(n)만에 되는 것 같은데?

어떻게 해야 b의 사이즈가 줄어들까?



*/