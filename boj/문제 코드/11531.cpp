#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<char, int> wrongCnt;

    int n;
    char ch;
    string res;

    cin >> n;

    int ans = 0, c = 0;;
    while (n != -1) {
        cin >> ch >> res;

        if (res == "right") {
            ans += n + wrongCnt[ch] * 20;
            c++;
        }
        else {
            wrongCnt[ch]++;
        }

        cin >> n;
    }

    cout << c << ' ' << ans;
    return 0;
}
