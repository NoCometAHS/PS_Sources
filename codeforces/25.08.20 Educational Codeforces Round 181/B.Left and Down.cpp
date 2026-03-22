#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

LL gcd(LL a, LL b) {
    return (b == 0 ? a : gcd(b, a%b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL x, y, n;
        cin >> x >> y >> n;
        
        LL  _gcd = gcd(x, y);
        if (x/_gcd > n || y/_gcd > n) {
            cout << 2 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }
    return 0;
}

/*
accepted
*/
/*
0~k 범위 숫자 2개
각각 왼쪽, 오른쪽으로 움직임.

숫자 페어 첨 고르면 1, 아님 0의 비용.

비용만 최소화 시켜서 0, 0으로 이동.

1,1 혹은 0, 1 혹은 1, 0만 써도 됨.
-----------
비용은 무조건 1 아님 2 임.

2개 이상 써야하는 경우면  (0,0), (0,1), (1,0) 셋 중 2개 써서 처리 가능.

x, y

x = m*a
y = m*b

를 만족시키는 a, b가 있으면 됨. ->  공약수 -> 최대 공약수가 찾기 쉬우니깐 찾자.

다른 공약수를 써야지 k의 안에 들어가는 경우가 있지 않을까? -> ㅇㅇ 있어.

아니네, 최대 공약수를 찾으면 k 안에 들어가야하는  a, b는 최소가 되기 때문에 오히려 최대 공약수 찾아야 하네.
*/