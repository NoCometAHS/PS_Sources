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

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;

    unordered_map<LL,LL> lt, rt;
    for (int i = 0; i < n; i++) {
        rt[arr[i]]++;
    }

    LL ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 5 == 0) {
            LL d = arr[i]/5;
            LL Ai = 7*d, Ak = 3*d;

            ans += lt[Ai]*lt[Ak] + rt[Ai]*rt[Ak];;
        }
        
        rt[arr[i]]--;
        lt[arr[i]]++;
    }
    

    

    cout << ans;
    return 0;
}


/*
A_j의 후보는 5로 나누어 떨어져야 함.
아닌 경우에는 나머지에 0.5가 곱해지는데 그러면 정수가 안 나옴.

3번째 조건을 만족시키기 위해서 A_j의 후보마다 왼쪽 오른쪽 따로 나눠서 A_i, A_k 한번에 찾아야 겠다.
7로 나누어 떨어지는 개수, 3으로 나누어 떨어지는 개수 곱해서 더하면 될 듯?

스위핑하면 그냥 구현 되는 거 아닌가

존나 귀찮네.
3,7으로 나누어떨어지는 인덱스들 넣은 배열 만들어서 bs하자.

7로도 나누어 떨어지는 게 중요한게 아니구나.
A_j가 정해지면 나머지 숫자들도 다 정해져버려.

multi set으로 양쪽 부분 구현?

굳이 multi set을 할 필요가 없었네
map 쓰면 되잖아.
*/