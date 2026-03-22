#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cin.ignore();

    string str, simon("Simon says");
    while (n--) {
        getline(cin, str);

        bool flag = true;
        for (int i = 0; i < simon.length(); i++) {
            if (i >= str.length() || str[i] != simon[i]) {
                flag = false;
                break;
            }
        }

        if (!flag) continue;

        for (auto it = str.begin() + simon.length(); it != str.end(); it++) cout << *it;
        cout << '\n';
    }
    return 0;
}
