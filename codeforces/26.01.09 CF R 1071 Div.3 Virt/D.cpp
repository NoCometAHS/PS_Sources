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

        unordered_set<int> chk;
        int cur = (1 << n) - 1;
        for (int i = 0; i <= n; i++) {
            chk.insert(cur);
            cout << cur << ' ';

            for (int k = 1; k < (1 << (i - 1)); k++) {
                int t = (k << (n - i + 1)) | cur;
                chk.insert(t);
                cout << t << ' ';
            }
            
            cur >>= 1;
        }


        for (int i = 0; i < (1 << n) - 1; i++) {
            if (chk.count(i)) continue;

            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
S(p)를 가장 크게 하는 p 중에 사전적으로 앞서는 순열 찾기.

1의 개수가 가장 많은 놈을 앞에 세우는 게 중요해.
2^n - 1 이 의심할 여지 없이 0번 자리고
그다음부터 뭘 하든 1이 하나씩 사라지는데?

사전순으로 앞서야하니
맨 앞의 비트가 꺼진 얘를 놓아.
맨 앞에서 2개의 비트가 꺼지든, 맨 앞에서 2번째 비트만 꺼지든 합은 똑같아.

그렇다면,
2^n - 1
맨 앞에서부터 1개 꺼진수
맨 앞에서부터 2개 꺼진수
...
전부 꺼진 수.
그리고 나머지 오름차순 정렬

숫자 개수를 더 많게 할 수 있는 거 아니냐
1111
0111
0011
0001
0000
이런 식으로 했지만

1111
0111
1011
0001
1001
...

이미 꺼진 놈들 안에 숫자 넣어서
S(p)를 더 크게 만들 수 있잖아. 아;;;
*/