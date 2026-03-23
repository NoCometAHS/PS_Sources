#include "bits/stdc++.h"

using namespace std;
using LL = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> cnt(1010, 0);
    int ave = 0;

    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;

        ave += num;
        cnt[num]++;
    }

    int ans, c = 0;
    for (int i = 10; i < 1010; i++) {
        if (cnt[i] > c) {
            c = cnt[i];
            ans = i;
        }
    }

    cout << ave/10 << '\n' << ans;
    return 0;
}