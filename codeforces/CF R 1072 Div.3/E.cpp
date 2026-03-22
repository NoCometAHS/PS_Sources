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
        int n;
        cin >> n;

        vector<LL> arr(n);
        for (auto& i : arr) {
            cin >> i;
        }

        vector<LL> diff;
        map<LL, vector<LL>> cnt;
        for (int i = 1; i < n; i++) {
            LL val = abs(arr[i] - arr[i-1]);
            diff.push_back(val);

            cnt[val].push_back(i-1);
        }

        set<iipair> grps;
        grps.insert({-1e9, -1e9});
        grps.insert({1e9, 1e9});
        for (int i = n - 1; i >= 1; i++) {
            if (!cnt[i].empty()) {
                for (auto& idx : cnt[i]) {
                    auto ret = grps.lower_bound({idx, idx});

                }
            }
        }


        
    }
    return 0;
}

/*
최소 2 원소를 가지고, 인접한 2 수의 차이가 최소한 k 일때 k-exquisite

순열 p길이 n인.
k : 1 to n -1 에서찾아라 k-exquisite 연속한 부분 배열 찾기.

---

차이만 가지고 있는 배열을 만들 수 있어
4 3 2 1

큰 k 부터 하고
누적해가면 될 것 같고.

연속한 것이 없어 순열이라.
차이 배열의 값도 순열이야. ㄴㄴ 아님.

1 2 3
-> 1 1

누적해 가는 게 중요한 듯.
연속되는 부분에는 (연속한 길이) * (연속한 길이 + 1) / 2 로 계산.




연속 구간을 set으로 관리?
이것도 계속 배열 돌아야 함.

*/