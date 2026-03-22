#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;

    while (str != "end") {
        if (str.front() == 'a') {
            cout << "Panthera tigris\n";
        }
        else if (str.front() == 't') {
            cout << "Pinus densiflora\n";
        }
        else {
            cout << "Forsythia koreana\n";
        }

        cin >> str;
    }
    return 0;
}
