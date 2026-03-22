#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc, s, k, n, ans;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cin >> s >> k >> n;

        cout << "Case #"<< i  << ": " << min(1+s, k - n + s - n + 1)+k-1 << "\n";
    }
    return 0;
}


/*
N개의 레벨, 현제는 K레벨, S 레벨가서 칼뽑기.

1. 1레벨부터 다시 시작하기
2. S레벨까지 가고 S레벨부터 다시 깨기

뭘 하든지 1분
*/
