#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, qCnt;
    cin >> n >> qCnt;

    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!arr[i]) continue;

        ans++;
        while (i < n && arr[++i]);
    }


    while (qCnt--) {
        int q;
        cin >> q;

        if (q) {
            int idx;
            cin >> idx;
            idx--;

            if (arr[idx]) continue;
            ans++;
            arr[idx] = 1;

            if (idx - 1 >= 0 && arr[idx - 1]) ans--;
            if (idx + 1 < n && arr[idx + 1]) ans--;
        }
        else {
            cout << ans << '\n';
        }
    } 
    return 0;
}

/*
idx가 , l, r 안 이지만,

l보다는 idx가 크니깐 벗어나는 거 아니냐?

r, l 범위로 넣는다면?

벗어나진 않지만,
얘간 왼쪽 밖에 있는 지를 검사 해 줘야 하네.

---

연속한 1의 그룹 개수를 관리 하면 됨.

배열에 다 넣어 둬.
처음만 전체 돌면서 그룹 개수 세.

0번에 대해서는 계속 관리하는 답을 출력하면 됨.
1번에대해서는

일단 그룹의 개수를 늘려.
인접한 칸에 검정있는 검정 개수만큼 빼줘.

*/