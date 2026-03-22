#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, x;
    cin >> n >> x;

    if (x < n || n*26 < x) {
        cout << "!";
        return 0;
    }

    string ans;
    for (int i = 0; i < n; i++) ans.push_back('A');


    x -= n;

    for (int i = n-1; i >= 0 && x > 0; i--) {
        if (x >= 26) {
            ans[i] = 'Z';
            x -= 25;
        }
        else {
            ans[i] = 'A' + x;
            x = 0;
            break;
        }
    }

    cout << ans;

    return 0;
}

/*
x를 나타내는 길이 n의 문자열은 여러개인가? ㅇㅇ ac나 bb나 같음

작은 문자열을 가장 많이 두기 위해 큰수를 계속 빼가야함.
구현이 힘드니깐

일단 a로 다 채워두고
바꾸자 끝에서부터
*/
