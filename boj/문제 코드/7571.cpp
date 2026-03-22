#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    TwoVector<int> arr(2);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        arr[0].push_back(a);
        arr[1].push_back(b);
    }

    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].begin(), arr[1].end());

    vector<int> mid{arr[0][m/2], arr[1][m/2]};

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < m; k++) {
            ans += abs(mid[i] - arr[i][k]);
        }
    }

    cout << ans;

    return 0;
}

/*
일단 배열로 표현 못 함.

그 1차원 배열에서 모두 같은 값으로 바꿀 떄, 어떤 값이 변화량이 가장 적냐 하는 문제 2차원 버젼 아니냐?
중간값이 답이였던 것 같은데.

x, y축이 연관이 없으니 각자 중간값 찾으면 될 것 같은데.

*/