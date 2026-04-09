#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, w, h;
    cin >> n >> w >> h;

    int dia = w*w + h*h;

    while (n--) {
        int l;
        cin >> l;
        if (l*l <= dia) cout << "DA\n";
        else cout << "NE\n";
    }
    
    return 0;
}