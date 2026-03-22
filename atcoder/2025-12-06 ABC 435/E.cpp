#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    vector<iipair> arr(q);
    for (auto& [l, r] : arr) cin >> l >> r;

    sort(arr.begin(), arr.end());

    int end = 0;
    int ans = 0;
    for (auto& [l, r] : arr) {
        if (end + 1 < l) {
            ans += l - end - 1;
        }

        end = max<LL>(end, r);
    }


    cout << ans;

    return 0;
}

/*
흰색으로 칠해진 n개의 공간. 번호는 왼쪽 1부터 시작


q개의 쿼리
l, r가 주어짐
[l, r]을 검게 칠해

흰색 개수는?

---

넓은 범위의 색칠을 어떻게 할까를 질문.

~~연산 순서가 의미 X~~

정렬
겹치면 연산도 합쳐버려

순서가 상관 있어, 계속 출력 해야해 남은 개수를.

영역이 안 겹치는 것끼리만 가지고 있으면 안 되나?

차라리 몇 개 없어지는 지를 알면 좋을 것 같기도 하고.

----
실제로 칠하진 못해.

영역 범위를 가지고 있지 않고 칠해진 부분을 알 수는 없을까? XX


연산끼리는 합쳐질 수 있다.

거꾸로 진행 할 수 있나? 

---
중요한건
연산끼리 겹쳐서 이미 뺀 값을 또 뺄 수가 있다는 점.
그 외에는 그냥 길이만큼 빼주기만 하면 됨.

겹쳤는 지 안 겹쳤는 지를 잘 확인 할 수 있으면 되겠다.

O(n)만에 찾으면 무조건 TLE
로그시간에 찾기?
이분탐색-> 배열 정렬된 상태 유지가 안 됨.
set

sqrt composition?
31,622 개의 버켓만 관리하기??
애매 모호 하네.

좌표 압축하고 실제로 칠해버리기?

좌표 압축 하고, prefix sum??
이것도 바로바로 답이 안 나오는 것 같은데

좌표 압축, lazy seg??
압축한 뒤로의 결과를 어떻게 해석해야 하지가 문제 같은데

*/