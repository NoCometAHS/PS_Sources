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

    string korea = "KOREA", yonsei = "YONSEI";
    int idx1 = 0, idx2 = 0;

    for (auto& ch : str) {
        if (ch == korea[idx1]) idx1++;
        if (ch == yonsei[idx2]) idx2++;

        if (idx1 == korea.length()) {
            cout << "KOREA";
            break;
        }
        else if (idx2 == yonsei.length()){
            cout << "YONSEI";
            break;
        }
    }

    

    return 0;
}
