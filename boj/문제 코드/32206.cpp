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

    string str;
    cin >> str;

    cout << (n+1)*26 - n;
    return 0;
}

/*
바로 앞에 글자를 추가하면 겹치는 경우가 생기는 듯.
*/