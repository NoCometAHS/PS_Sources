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
    int curMx = 1, ans = 0;

    for (int i = 0; i < n; i++) {
        if (!curMx) break;

        int num;
        cin >> num;
        
        ans++;

        curMx = max(curMx-1, num-1);
    }

    cout << ans;

    return 0;
}

/*
연속한 1을 뛰어 넘을 수 있다면 합쳐
아니면 제외.
그랬을 때 가장 큰 수.

첫번째 도미노 넘어졌을 때 보는거였네 ㅋㅋㅋㅋㅋㅋㅋㅋㅋ
*/