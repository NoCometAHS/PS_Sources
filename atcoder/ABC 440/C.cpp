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
        int n, w;
        cin >> n >> w;

        vector<LL> arr(n);
        for (auto& i : arr) cin >> i;


        if (arr.size() < 2*w) {
            arr.resize(2*w, 0);
        }

        vector<LL> arr2;
        for (int i = 0; i < 2*w; i++) {
            LL sum = 0;
            for (int k = i; k < n; k += 2*w) {
                sum += arr[k];
            }

            arr2.push_back(sum);
        }


        LL ans, sum = 0;
        for (int i = 0; i < w; i++) {
            sum += arr2[i];
        }

        ans = sum;

        LL lt = 0, rt = w;
        for (int i = 0; i < 2*w; i++) {
            sum -= arr2[lt];
            sum += arr2[rt];


            lt = (lt + 1) % (2*w);
            rt = (rt + 1) % (2*w);

            ans = min(ans, sum);
        }

        cout << ans << '\n';
    }

    return 0;
}

/*
Paint square i black for all integers i satisfying 1≤i≤N such that the remainder when (i+x) is divided by 2W is less than W.
x를 알아서 골라,
i번 사각형을 칠할 거야.
i는 [1, n] 범위인데, 
(i+x)가 2w로 나눠줬을때 나머지가 w 미만일 때

--

어떤 x를 골라야 
w는 주기야

2w가 있을 때
앞의 w는 칠하고
뒤의 w는 안칠하고를 반복해

w-1개 칠하고, w개 안 칠하고, w개 칠하고....

x는? 
편하게 생각하기 위해서

x는 w-1부터 시작한다고 하자.

그러면 주기도
w개 안 칠하고, w개 칠하고로 반복.

n+ n / w * w
브포로 되나?
---

머리가 안 돌아간 다 ㅋㅋ;;


(i+x) % 2w < w

x == w-1
w = 4
b b b b w w w w b b b b w w w w ...

주기가 2w

그냥 브포 한다고 하면?

2w * n
시간 초과.

n에 대해서 변하는 곳만 본다면?
많아봤자. n/w개

2w*n/w
2n<- ㄱㄴ

---
변하는 곳이 어딘지 어떻게 알지.


*/