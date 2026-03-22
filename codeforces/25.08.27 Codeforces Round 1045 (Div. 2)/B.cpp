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
양의 정수 n개로 이루어진 배열. 양의 정수 k.

배열의 모든 원소에 각각 0혹은 k를 더할 수 있다. 한 연산에서.

최대 k번 해서 gcd(arr) > 1로 만들라. -> 공약수가 생기도록 해라.

----
어떤 수에 k를 더하면 약수가 어떻게 변하지?

k가 4일 때,
3 , 7, 11, 15(3 + 4*3), 19

5, 9(5 + 4), 13,  17, 21

----------
배열에 k씩 띄어서 표시한다고 생각해보자.

사실상 mod k 한 값에서 부터 한 것과 동일한 거 아냐?

3 + y*k
1 + (1+x)*k

같은 수는 절대 안 나와.

[(n-1)*k, n*k)의 범위에서 계속 반복된다.



*/