#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

constexpr LL mod = 998244353;

LL fact[55];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < 55; i++) fact[i] = fact[i-1] * i % mod;

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL n;
        cin >> n;

        LL mx = -1;
        vector<LL> arr(n+1);

        for (int i = 0; i <= n; i++) {
            cin >> arr[i];

            if (i > 0) mx = max(mx, arr[i]);
        }

        LL sum = 0, mxCnt = 0;;
        for (int i = 1; i <= n; i++) {
            mxCnt += mx == arr[i];

            sum += max(0LL, mx - 1 - arr[i]);
        }

        if (sum > arr[0]) {
            cout << 0 << '\n';
        }
        else if (sum == arr[0]) {
            cout << fact[mxCnt] * fact[n-mxCnt] % mod << '\n';
        }
        else {
            LL l = arr[0] - sum;

            mxCnt = 0;
            for (int i = 1; i <= n; i++) {
                arr[i] = max(arr[i], mx - 1);
                LL dif = mx  - arr[i];

                if (dif <= l) {
                    arr[i] += dif;
                    l -= dif;
                }
                else {
                    arr[i] += l;
                    l = 0;
                }

                mxCnt += arr[i] == mx;
            }

            LL ans = 0;
            if (mxCnt == n) {
                l %= n;
                cout << fact[n] / fact[n - l] * fact[n - l] % mod << '\n';
            }
            else {
                cout << fact[n-1] / fact[n-1 - (mxCnt-1)] / fact[mxCnt-1] * fact[mxCnt] % mod * fact[n - mxCnt] % mod  << '\n';
            }
        }


    }
    return 0;
}

/*
n명이 있는 그룹.
0 ~ n까지 인덱스의 데코 박스.

i번째 박스에a[i]개의 데코가 있음

길이 n의 순열 p가 공정하려면 밑의 연산으로 모든 데코를 써야한다.

사람 p[1]이 0번째 박스 혹은 p[1]번째 박스로부터 데코 가져가서 씀
사람 p[2]이 0번째 박스 혹은 p[2]번째 박스로부터 데코 가져가서 씀

계속함.

모든 장식이 쓰일 때까지 사이클 형식으로 돌아간다.

해당 순번 때 쓸 데코가 없어서는 안 됨. 이런 상황이면 공정하지 못 함.

공정한 순열의 개수는?
모듈로로 나눠서 구해.

---

버퍼용 0번 박스
그리고 사람마다 할당된 박스.

사람마다 할당된 박스가 중요하겠다, 0번 박스는 그냥 가져다가 쓰면 되니깐.

많은게 아무레도 앞으로 가야겠지? 더 반복될 여지가 있으니깐

---
0번째 박스만 없으면
데코의 최대값 - 최소값이 <= 1 일 때 정답이 있고 잘 구하면 되는데.

일단 데코의 최댓값 - 1 만큼은 바퀴를 돌아야해.
최댓값을 맨 앞에 두면 되니깐.


최댓값을 mx라고 했을때
max(0, mx - 1 - a[i])의 합이 a[0] 보다 크면 가능한 경우가 없어.


---
case work
max(0, mx - 1 - a[i])의 합을 sum 이라고 할 때

sum > a[0]
    무조건 0

sum == a[0]
    같은 수끼리의 순서 변경은 가능

    각 수마다 같은 수 개수의 곱


- sum < a[0]
    일단 남은건 다 써야 한단 말이지.
    l = a[0] - sum

    i) l이 모든 데코를 mx개 이상으로 만들 수 정도로 많을 때,

        최대값 - 최소값 <= 1이 되도록 공정하게 뿌리고

        n! / (n - 새로운 mx 개수)!  * 각 수마다 같은 수 개수의 곱


    ii) l이 모든 데코를 mx개 이상으로 만들 수 없을 때
        최소한 답이 되도록 만들어,
        모든 데코가 mx - 1개 씩은 될거야. 
        여기서 mx개가 될 수 있는 얘들도 몇개 있겠지. 그렇게 더해

        n! / (n - mx 개수)! ) * 각 수마다 같은 수 개수의 곱
        아니 여기 코드 이상함;;; 시봐 다 풀었는데;;;;;;;;;;
        mxcnt 구하는게 틀린듯?






1

4 3 3 3
*/