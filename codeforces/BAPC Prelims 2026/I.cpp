#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    cin >> w >> h;

    TwoVector<iipair> arr(h, vector<iipair>(w, {-1, -1}));

    map<char, int> dir{{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}}
    int arrow;
    cin > arrow;

    while (arrow--) {

    }


    return 0;
}