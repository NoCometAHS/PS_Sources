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
        string str;
        cin >> n >> str;

        str += str;
        
        int ans = 0, cnt = 0, st = 0;
        

        while (str[st] == '1') st++;

        for (int i = st; i < str.length(); i++) {
            if (str[i] == '0') {
                cnt++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }

        if (ans == 1e9) cout << "0\n";
        else cout << ans << '\n';
    }
    return 0;
}

/*
길이 n 이진 문자열
모든 문자가 1이 되도록

[1, n]안에서 하나 선택 : d
d만큼 오른쪽 쉬프트.
결과 문자열에서 1인 부분이랑 or 연산

d만큼 비용이 드는데 최소 비용

---
오른쪽 쉬프트 한 만큼 비용이 들어

되기만 하면 된다면?
그냥 1만 반복하면 됨.

?? 계속 1만 더하면 되는 거 아닌가?
만약 3을 한번에 움직이면 될거였으면
1,1,1을 해도 되는 거잖아.

구현이;;
다음 1로부터 가장 멀리 떨어져 있는 거리가 답이다.
*/