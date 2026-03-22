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
    int tc = 1;

    while (n) {
        vector<string> arr(n);
        for (auto& s : arr) {
            getline(cin, s);
        }

        set<int> a;
        for (int i = 0; i < 2*n - 1; i++) {
            int num;
            char ch;
            cin >> num >> ch;

            if (a.count(num)) {
                a.erase(num);
            }
            else {
                a.insert(num);
            }
        }

        cout << tc++ << " " << arr[*a.begin()-1] << '\n';

        cin >> n;
        cin.ignore();
    }
    return 0;
}
