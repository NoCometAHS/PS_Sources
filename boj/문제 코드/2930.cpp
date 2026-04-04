#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<char, char> win({{'R', 'S'}, {'S', 'P'}, {'P', 'R'}});

    auto resFunc = [&] (char me, char op) {
        if (win[me] == op) return 2;
        if (win[op] == me) return 0;
        return 1;
    };

    int n, m;
    string me;
    cin >> n >> me >> m;
    
    vector<string> op(m);
    for (auto& i : op) cin >> i;

    int sangun = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        int r = 0, s = 0, p = 0;
        for (int k = 0; k < m; k++) {
            r += resFunc('R', op[k][i]);
            s += resFunc('S', op[k][i]);
            p += resFunc('P', op[k][i]);
            sangun += resFunc(me[i], op[k][i]);
        }

        ans += max({r,s,p});
    }

    cout << sangun << '\n' << ans;

    return 0;
}
