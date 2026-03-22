#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;


map<char, int> rsp({{'R', 1}, {'S', 2},{'P', 3},});

bool leftWin(char ch1, char ch2) {
    int v1 = rsp[ch1] % 3 + 1, v2 = rsp[ch2];

    return v1 == v2;
}

bool leftDefeat(char ch1, char ch2) {
    int v1 = (rsp[ch1]-2+3) % 3 + 1, v2 = rsp[ch2];

    return v1 == v2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n, p1 = 0, p2 = 0;
        cin >> n;

        while (n--) {
            char ch1, ch2;
            cin >> ch1 >> ch2;

            if (leftWin(ch1, ch2)) p1++;
            else if (leftDefeat(ch1, ch2)) p2++;
        }

        if (p1 < p2) cout << "Player 2\n";
        else if (p1 > p2) cout << "Player 1\n";
        else cout << "TIE\n";
    }

    return 0;
}
