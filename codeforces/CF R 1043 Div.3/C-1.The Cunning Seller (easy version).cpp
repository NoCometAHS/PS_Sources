#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

LL mypow(LL a, LL b) {
    LL ret = 1;
    for (LL i = 0; i < b; i++) ret *= a;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    LL costs[20];
    for (int i = 0; i < 20; i++) {
        costs[i] = mypow(3, i+1) + i * mypow(3, i-1);
    }

    while (tc--) {
        int n;
        cin >> n;

        vector<int> res;
        while (n) {
            res.push_back(n % 3);
            n /= 3;
        }
        
        LL ans = 0;
        for (int i = 0; i < res.size(); i++) {
            ans += costs[i] * res[i];
        }

        cout << ans << '\n';
    } 
    return 0;
}


/*
3개의 수박 팜.

3^x개를 3^(x+1) + x * 3^(x-1)원에 팜. x는 음이 아닌 정수. -> 딜이라고 부름

n개 사고 싶음.
딜을 횟수를 최소하하고 싶음.

n개의 수박 사는데 드는 최소한의 코인 , 하지만 거래도 최소인.

최소 코인 개수 구해.


x: 0 1  2  3   4   5    6
w: 1 3  9  27  81  243  729
c: 3 10 33 108 351 1134 ...
**-> 이렇게 몇 개 정리해 보니깐 c-2  풀 때 도움이 됐다.**
한개씩은 살 수 있으니깐 무조건 가능은 함. 

---------
거래 횟수가 최소로 같은데 코인은 덜 쓰는 게 가능한가?

수박 많이 산 거래를 빼버리면 거래 횟수가 무조건 늘어야함. 아니면 최소라는 가정에서 아웃.

수박을 적게 산 거래를 빼버리면 최소라는 가정에서 아웃.

적당한걸 뺀다? 다 거래 횟수가 늘거나, 최소라는 가정에서 모순.

-> 최소 횟수로 거래만 할 수 있으면 된다.
--------

x 뒤에 있는 거래들 하나씩 다 빼도 x+1을 넘질 못 해.

그리고 각각 같은 거래를 2번 이상 하는 건 비효율적이야.

3진수의 숫자로 표현할 수 있는가 아니냐.

--------
bfs?

*/