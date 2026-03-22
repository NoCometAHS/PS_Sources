#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

LL GetCnt (LL x, vector<LL>::iterator b, vector<LL>::iterator e) {
    return upper_bound(b, e, x) - lower_bound(b, e, x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;

    vector<LL> arr(n);
    for (auto& i : arr) cin >> i;
    sort(arr.begin(), arr.end());

    LL sum = accumulate(arr.begin(), arr.end(), 0), mx = arr.back(), mxCnt = GetCnt(mx, arr.begin(), arr.end());
    

    return 0;
}

/*
일단 "어떤 원소"는 가장 큰 원소 일 수 밖에 없어. 아니면 합이 원소와 같을 수 없으니깐.

가장 큰 수를 mx라고 하고, 배열은 정렬된 상태라고 하자.

1. mx가 있는 상태
mx를 뺀 수열의 합을 sum.

mx 빼고 배열을 돌면서
(sum - mx - arr[i])의 개수만 답에 더해주기.



2. mx를 지운 상태.
mx바로 전 수가 mxx고, 그 수를 뺀 수열의 합은 sum

수열에서 (sum - mxx)의 개수가 모든 경우의 수.


만약 mx가 여러개라면? 그 개수 만큼만 곱해주면 될 듯..? ㄴㄴ.
5개 이상이면 무조건 불가능
4개면 mx 외 다른 숫자가 없을 때, 답은 6
3개면 mx 외 다른 숫자의 합이 mx 일때 3, 아니면 0
2개면 수열에서 (sum - mx)의 개수  * 2

---
쉬벌 안 되데내.
*/