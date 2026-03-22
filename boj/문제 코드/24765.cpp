#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int scoring(iipair a) {
    if (a.first < a.second) swap(a.first, a.second);

    if (a.first == 2 && a.second == 1) return 1000;
    else if (a.first == a.second) {
        switch (a.first) {
            case 6 : return 999;
            case 5 : return 998;
            case 4 : return 997;
            case 3 : return 996;
            case 2 : return 995;
            case 1 : return 994;
        }
    }
    
    return a.first*10 + a.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    iipair a, b;
    cin >> a.first >> a.second >> b.first >> b.second;

    while (a.first) {
        int one = scoring(a), other = scoring(b);

        if (one < other) cout << "Player 2 wins.\n";
        else if (other < one) cout << "Player 1 wins.\n";
        else cout << "Tie.\n";

        
        cin >> a.first >> a.second >> b.first >> b.second;
    }
    return 0;
}
