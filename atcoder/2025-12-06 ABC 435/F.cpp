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
n개의 캣타워 키는 P[i]

그리고 n개의 숫자가 있는 순열임
거리는 |i - j|로 구함.

높이가 n인 캣타워에 고양이.
반복적으로 고르고 캣타워 없앨거다.

사라지는 캣타워 위에 고양이가 없으면 고양이는 안 움직임.

사라지는 캣타워 위에 고양이가 있고, 최소한 하나의, 인접한 왼쪽 오른쪽에 타워가 있다면, 고양이는 인접한 타워로 계속 가면서 갈수 있는 가장 큰 타워로 감

움직일 곳이 없으면 끝

---

고양이가 없는 타워를 없앨 필요가 있나?
있네
2 1 4 3 이면
바로 4 없애면 고양이는 높이 3인 곳으로 가고 끝나버려.

고양이가 움직인다는건 무슨 뜻이지?
왼쪽과 오른쪽 구역 중에서 큰 값이 없는 구역을 버린다는 뜻.
한 번 움직일 때마다 1개 이상의 타워가 사라져.

이동거리가 많을 곳으로 움직이고 싶은데.


---
카르테시안 트리 구성하고
dp 라니
와우
지린다.

ㅇㅇ 솔루션이 말하는 것처럼, 상태가 유일하네.
*/