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

        vector<int> arr(n);
        int mn = 1e9;
        for (auto& i : arr) {
            cin >> i;
            mn = min(mn, i);
        }

        int ans = mn;
        int mx = 1e9;
        for (auto& i : arr) {
            if (i == mn) continue;

            i -= mn;
            mx = min(mx, i);
        }

        cout << max(ans, mx) << '\n';
        
    }
    return 0;
}

/*
k가 1이면 무조건 가능하고

k 가 결정된다는 건
k 미만의 수들은 못바꾼다는 말이야.

그럼 커지게 되었을 때 불가능하게 되는 경우가 생기겠네.
최솟값과 그다음 최솟값이 있을때,

그 다음 최소값 이상의 수는 절대 안 돼.

어떤 수로 같게 만들 수 있을까
k가 최솟값이하라면 무조건 돼.
다 0으로 만들어 버리면 되니깐.


~ 다 됨 ~ mn ~ ? ~ mnn - 1 ~ 안 됨 ~

mn과 mnn-1 사이의 값이라는 거네.


k가 mn 초과가 되려면
모든 수의 나머지가 mn으로 만들 수 밖에 없어

그러한 수가 없으면 최대의 k는 mn

어떤 수로 나눴을 때 나머지가 mn이 된다는 걸 알 수 있나?

a_i = pq + mn  

a_i - mn = pq

모두 mn을 뺏을 때 수열을 b

b_i의 약수 중 가장 큰 수들 중 최솟값이 답이되는 k
? 약수 중 가장 큰수는 b_i 잖아.
*/