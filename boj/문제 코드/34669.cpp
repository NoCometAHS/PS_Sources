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
        LL c, k;
        cin >> c >> k;

        cout << c*k << ' ' << c/k << '\n';
    }
    return 0;
}

/*
수요 기대 상수가 있고

이건 비환승역 개수 * 기대 수요로 구하고

기대 수요의 최대 최소값 구하는 거구나.


최대 값은 전부 하나씩 연결한 걸까?
그런 모두 (기대 수요 = 기대 수요 상수) 가 성립하니깐

최소 값은
전부 다 같이 연결 한 거겠네?

c/k
*/