#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    vector<iipair> cards(N);

    for (auto& [f, b] : cards) cin >> f >> b;

    for (int i = 0; i < K; i++) {
        vector<LL> sub(N);
        
        for (int k = 0; k < N; k++) {
            sub[k] = cards[k].first - cards[k].second;
        }

        LL mn = 0, cur = 0;
        LL mnl = 0, mnr = 0, l = 0, r = 0;
        for (int k = 0; k < N; k++) {
            if (cur + sub[k] >= 0) {
                cur = 0;
                l = r = k+1;
            }
            else {
                cur += sub[k];
                r = k;
            }


            if (cur < mn) {
                mn = cur;
                mnl = l, mnr = r;
            }
        }

        if (mn >= 0) break;
        for (int k = mnl; k <= mnr; k++) swap(cards[k].first, cards[k].second);
    }


    LL ans = 0;
    for (auto& [f, b] : cards)  {
        ans += f;
    }
    cout << ans;
    return 0;
}

// 11분 남음