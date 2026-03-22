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

    int ans = 0;
    for (int i = 1; i*3 < n; i++) {
        for (int k = 1; k*3 < n - i*3; k++) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}

/*

m * 3

a*3 + b*3 + c*3

a + b + c = m

수 크면 그냥 수학으로 풀 수 있는 것 같은데.

m개의 3

3 사이에 막대기 2개 꽂는 경우 생각 할 수 있는데

m-1 에서 2개를 뽑는 경우.
(m-2) * (m-1) / 2
*/
