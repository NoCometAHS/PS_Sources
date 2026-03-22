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

    vector<int> cnt(5, 0);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        cnt[s]++;
    }

    int ans = cnt[4];
    int r = min(cnt[3], cnt[1]);

    cnt[3] -= r;
    cnt[1] -= r;

    ans += r + cnt[3];
    
    r = min(cnt[2], (cnt[1]+1)/2);

    cnt[2] -= r;
    cnt[1] = max(0, cnt[1] - r*2);

    ans += r + (cnt[2]+1)/2 + (cnt[1]+3)/4;

    cout << ans;


    
    

    return 0;
}
/*
4는 그냥 담고

3이랑 1이랑 일단 같이 담아
3이 남으면 그냥 담고

1이랑 2랑 또 담아.
2가 남으면 (나은거+1)2개 더하고

1이 남아
(남은거+3)/4
*/