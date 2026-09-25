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
m개의 정수로 이루어진 array b을 hill이라고 한다. 1 <= k <= m인 어느 k 대해서 다음 조건 만족시
첫 k 원소는  증가한다.
마지막 m - k + 1은 감소한다.

n개의 구별된 정수로 이루어진 array a가 있다.
인덱스 i 고르고 swap(a_i, a_(i+2))를 할 수 있다.
a를 hill로 만들 수 있을까?


*/