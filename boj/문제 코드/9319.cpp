#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL tc;
    cin >> tc;

    while (tc--) {
        LL n, b;
        cin >> n >> b;

        iipair p;
        cin >> p.first >> p.second;

        vector<double> r(n);
        double sum = 0;
        for (int i = 0; i < n; i++) {
            double x, y, s;
            cin >> x >> y >> s;

            double len = (x-p.first)*(x-p.first) + (y-p.second)*(y-p.second);

            sum += r[i] = s/len;
        }


        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (r[i] <= 6 * (b + sum - r[i])) continue;
            ans.push_back(i+1);
        }

        if (ans.empty()) cout << "NOISE\n";
        else {
            for (auto& i : ans) cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}
