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

    vector<LL> shari(n), neta(m);
    for (auto& i : shari) cin >> i;
    for (auto& i : neta) cin >> i;

    sort(shari.begin(), shari.end());
    sort(neta.begin(), neta.end());

    int ans = 0;
    while (!shari.empty() and !neta.empty()) {
        if (shari.back()*2 < neta.back()) neta.pop_back();
        else {
            shari.pop_back();
            neta.pop_back();

            ans++;
        }
    }

    cout << ans;
    return 0;
}

/*
neta <= 2*shari


*/