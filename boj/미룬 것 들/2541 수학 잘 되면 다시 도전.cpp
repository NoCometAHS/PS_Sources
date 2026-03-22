#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}

/*
1번 규칙은 
기울기가 1인 직선위에 집합 원소가 존재한다는 것

2번 규칙은
시작수가 (짝, 홀), (홀, 짝) 인경우에는 사용 할 수 없어.

규칙을 적용할 수 있다고 하고, 시작수를 (x, y) {단, x < y} 일 때,
(1, z), (2^p, ?)의 형태로 작아지게 만들 수 있어. 그래봤자, 기울기 1인 직선 위고.

3번 규칙
처음 만들어진 직선이 y = x + d 에서 d가 0이면 의미 없는 규칙
그 외는


a = x + d
y = a + d

x = a - d 
y = a + d

(a - d, a + d)인 점들이 추가된다.
a가 집합안 임의의 쌍에서의 x, y에 둘 다 있어야 한다.

---
오우 시벌
수학적 관찰 미쳤네.
*/