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
        LL n;
        cin >> n;
        if (n <= 9) {
            cout << n * (n+1)/2 << '\n';

            continue;
        }
        int i = 1;
        LL digit = 1, digitCnt = 0, nines = 0;
        while (n > digit) {
            digitCnt++;
            nines += digit * 9 * i;
            digit *= 10;
            
            i++;
        }

        LL r = n - nines;
        LL lastNum = digit + r / (digitCnt+1) - 1;

        LL ans = 0;
        for (LL cur = lastNum, backCnt = 1; cur > 0; cur /= 10, backCnt = backCnt*10) {
            if (cur >= 10) {
                ans += cur/10 * backCnt * 45;
            }
            else {
                ans += (cur*(cur+1)/2) * backCnt;
            }
        }

        lastNum++;
        for (int i = 0; i < r % (digitCnt+1); i++) {
            ans += lastNum / digit;
            lastNum %= digit;
            digit /= 10;
        }

        cout << ans << '\n';
    }
    return 0;
}

/*
정수의 무한 수열. 연속한 양수 수열, 1부터 시작하는.

k번째 자리에서 잘랐다. 왼쪽 부분의 정수 합은? (k번째 수 포함.)

15
자리 수까지 붙여진 수열을 봐야하네.

한자리 숫자 9개
두자리 숫자 90개
... 900개
... 9000개
....

실제 자리수가 마지막 숫자의 자리수하고 같네.
--------
a자리 숫자임을 알았어
999..9 (9가 a-1개)를 뺀 결과값 r
r / a의 몫 s

s번째 a자리 숫자.
즉 10^(a-1) + s - 1가 온전히 나오는 마지막 수. (단 1자리 숫자면 걍 해라.)


어떤 수까지 포함된다는 걸 알면 답은 쉽게 구할 수 있을 것 같아.
*/