#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<iipair> arr(n);
    for (auto& [i, j] : arr) cin >> i >> j;

    sort(arr.begin(), arr.end(), [](iipair& a, iipair& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });



    vector<LL> dp;

    for (auto& [i, v] : arr) {
        LL cur = v;

        auto it = lower_bound(dp.begin(), dp.end(), cur);
        if (it == dp.end()) {
            dp.push_back(cur);
        }
        else {
            *it = cur;
        }

    }

    cout << dp.size();

    return 0;
}

/*
한 쪽이라도 겹치지 않는 수열이였으면
최장 증가 부분 수열 문제야.
n log n 만에 해결 가능해.

---

일단 사람 정렬

사람이 같은 자리에 서 있으면??
1. 수열 길이 늘리는 숫자
2. 작은 숫자

이거 뒤에 어떻게 되어 있느냐에 따라 다른데.
그럼 dp? 이미 dp긴 해 ㅋㅋ

앞쪽에 있는 경우가 정해지면 뒤쪽과는 연관이 없을까? ㄴㄴ  뒤쪽을 다 봐봐야지 겹쳐진 곳에서 결정 할 수 있어.

생략하고 하는 경우는 정렬의 의미가 없지.

인덱스별로 뒤쪽에 최대 증가하는 수열 값을 알 수는 없을까?

dp에 pq로 저장해볼까? 가장 작은 값만 볼 수 있게 ㄴㄴㄴ. 시작이 같은 연을 여러개 쓰잖아.
뒤에서 부터 해볼까, 의미 없는 거 아니냐.

---
1. 다 저장해 보기.
잘 모르겠네.
2. 여러번 dp 돌리기..?
시작 지점 같은데 여러개의 연 날리는 겨우

그냥 b[i]는 작은 순서로 정렬하라고??????
정렬 순서만 바꿔도 된다는게 무슨 뜻이야!!!!!!!!!
*/