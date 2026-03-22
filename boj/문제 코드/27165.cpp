#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> arr(n+1);
    vector<int> onePos;
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
        
        if (arr[i] == 1) onePos.push_back(i);
    }

    int move;
    cin >> move;

    if (onePos.empty()) {
        for (int i = 0; i + move <= n ; i++) {
            if (arr[i] >= 3 && arr[i + move] != 0) {
                cout << "YES\n";
                cout << i << ' ' << i + move;
                return 0;
            }
        }
    }
    else if (onePos.size() == 1) {
        int p = onePos[0];
        if (p + move <= n && arr[p + move] >= 1 ) {
            cout << "YES\n";
            cout << p << ' ' << p + move;
            return 0;
        }
        else if (p - move >= 0 && arr[p - move] >= 3) {
            cout << "YES\n";
            cout << p - move << ' ' << p;
            return 0;
        }
    }
    else if (onePos.size() == 2) {
        if (onePos[1] - onePos[0] == move) {
            cout << "YES\n";
            cout << onePos[0] << ' ' << onePos[1];
            return 0;
        }
    }
    cout << "NO";

    return 0;
}

/*
주사위 두 개.
정해진 방향으로 눈 수만큼 이동.

같은 눈이면, 두 주사위 2번씩 사용.
-- 쓸모 없네.

상대말 2개면 못잡고, 1개만 잡음.

목적지를 넘으면 못 움직임.

0번에 1개 이상의 말.
안전한상태로 만들어라.

---
무조건 움직여야해서, 1개짜리가 없을 때가 문제네.


----
1개짜리가 없을 떄, 간격이 move 인게 없으면 no
있으면 yes

1개만 있으면, 앞 move 간격에 돌 있으면 yes
뒤 move 간격에 돌 3개 이상이면 yes
그 외 no

2개 있으면, 2개 간격이 move면 yes
그 외 no

그 이상 있으면 무조건 no


*/