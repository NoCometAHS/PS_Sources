#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;

    bitset<32> ba(a), bb(b);

    LL ia = ba.to_ullong(), ib = bb.to_ullong();

    LL ans = ia * ib;

    int st = 63;
    for (st; st >= 0 && ((ans>>st) & 1) == 0; st--);

    while (st + 1) {
        cout << ((ans>>st) & 1);
        st--;
    }

    return 0;
}
