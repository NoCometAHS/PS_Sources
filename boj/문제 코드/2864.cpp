#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;
    
    string minA, minB, maxA, maxB;

    for (auto i : a) {
        if (i == '5' || i == '6') {
            minA += '5';
            maxA += '6';
        }
        else {
            minA += i;
            maxA += i;
        }
    }

    for (auto i : b) {
        if (i == '5' || i == '6') {
            minB += '5';
            maxB += '6';
        }
        else {
            minB += i;
            maxB += i;
        }
    }

    
    cout << stoi(minA) + stoi(minB) << ' ' << stoi(maxA) + stoi(maxB);
    return 0;
}