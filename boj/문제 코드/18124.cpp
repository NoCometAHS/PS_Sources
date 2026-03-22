#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;
    LL size = ceil(log2(n));
    LL squareCnt = (1LL << size);
    LL cutCnt = squareCnt - 1;
    LL leftCnt = squareCnt - n;

    leftCnt -= leftCnt % 2;

    cout << cutCnt - leftCnt/2;
    

    return 0;
}

/*
    세로로 먼저 자른다고 했을 때,
    길다란 사각형, 정사각형.. 순으로 반복

    최대 사각형 개수가 2배씩 늘어나네.
    자르는 횟수는 사각형 개수 -1 같은데
    2^x >= n
    x >= log_2(n)

    한번씩 덜 자를 때마다 2개씩 사라지네.

    자를 때 크기 종류가 2가지여야 한다가 지켜지나?
    4294967296
*/