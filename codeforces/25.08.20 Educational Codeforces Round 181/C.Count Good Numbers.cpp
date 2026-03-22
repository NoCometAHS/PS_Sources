#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL l, r;
        cin >> l >> r;

        l--;
        LL left = l - (l/2 + l/3 + l/5 + l/7 - l/6 - l/10 - l/14 - l/15 - l/21 - l/35 + l/30 + l/42 + l/70 + l/105 - l/210);
        LL right = r - (r/2 + r/3 + r/5 + r/7 - r/6 - r/10 - r/14 - r/15 - r/21 - r/35 + r/30 + r/42 + r/70 + r/105 - r/210);
        
        cout << right - left << '\n';
    }
    return 0;
}

/*
accepted
*/
/*
~두 수 이상으로 인수분해한 결과가 모두 소수라면 좋은 정수.~

** 소인수분해 결과의 소수가 모두 2자리 이상의 숫자면 좋은 정수. **
 l, r 사이의 수중 좋은 수 개수는?

 인버전 카운팅?

 2, 3, 5, 7 가 소인수가 아니면 된다.

 4 숫자로 나눈 값들 다 더하고, l - r + 1 에 빼주면 되는 거 아니냐.
*/