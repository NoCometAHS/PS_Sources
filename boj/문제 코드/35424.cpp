#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, m;
    cin >> n >> m;

    vector<LL> pos(n);
    for (auto& i : pos) cin >> i;

    LL stC = pos.front(), enC = stC, row = 1;
    LL ans = 1;
    for (int r = 1; r < n; r++) {
        stC = min(stC, pos[r]);
        enC = max(enC, pos[r]);
        row++;

        if ((abs(stC - enC)+1)*row > m) {
            ans++;
            stC = enC = pos[r];
            row = 1;
        }
    }

    cout << ans;

    return 0;
}

// 모든 행마다 하나씩 낙서이 있어.
// 한 행에 색종이 하나만 존재하도록 생종이를 덮어서, 모든 낙서 지우기.
// 색종이 넓이는 k 이하.
// 필요한 최소 색종이 개수

/*
일단 n번 색종이 쓰면 무조건 다 가려진다.
* . . . . . . . . . . . .
. . . . . * . . . . . . .
. . . . . . * . . . . . .
. . . . . . . * . . . . .
. . . . . . . . * . . . .

밑에 얘를 가릴 수 있으면 무조건 가리는 게 이득 같은데.
안 가릴 이유가 없어.
*/