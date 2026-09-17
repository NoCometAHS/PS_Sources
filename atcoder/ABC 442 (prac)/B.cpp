#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;

    bool playing = false;
    int volumn = 0;
    while (q--) {
        int op;
        cin >> op;

        if (op == 1) volumn++;
        else if (op == 2) volumn = max(volumn-1, 0);
        else {
            playing = !playing;
        }


        if (playing and volumn >= 3) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }

        cout << '\n';

    }
    return 0;
}