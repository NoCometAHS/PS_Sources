#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        for (int i = 0; i < num/5; i++) cout << "++++ ";
        for (int i = 0; i < num%5; i++) cout << "|";
        cout << '\n';
    }
    return 0;
}
