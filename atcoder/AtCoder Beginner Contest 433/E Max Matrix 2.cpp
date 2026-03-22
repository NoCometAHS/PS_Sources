#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}

/*
길이 N, M 인 수열 주어짐.

다음 조건 만족하는 행렬 찾아라.

1. 원소는 [1, n*m]을 만족.
2. 모든 원소는 서로 다른다.
3. i 행의 최대값은 X[i]다.
4. i 열에서 최대값은 Y[i]다.


---
두 수열에 같은 수가 있으면 A[i, j]에 그 수 넣으면 됨.

1.
X수열에 있는 수는 |X| 이상이어야 함.
Y수열에 있는 수는 |Y| 이상이어야 함.

2.
무조건 넣어야 하는 수 넣기.

3.
규칙 성립하게 수 넣기?
    3-1.
    각 행, 열마다 넣어야 하는 수, 넣을 수 있는 수를 가진 벡터를 가지고 있어.
    
*/