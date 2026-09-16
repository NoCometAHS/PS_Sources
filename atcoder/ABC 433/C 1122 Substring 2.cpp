#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] + 1 != str[i+1]) continue;

        ans++;
        for (int l = i-1, r = i+2; l >= 0 && r < str.length() && str[l] == str[l+1] && str[r-1] == str[r]; l--, r++) ans++;
    }

    cout << ans;
    return 0;
}

/*
숫자로 구성된 문자열 T.
다음 조건 만족시 1122-string

1. T가 비어있지 않음
2. T의 길이가 짝수
3. T의 1번째 문자와 |T|/2번째까지 같은 숫자임
4. |T|/2 + 1부터 마지막 문자까지 다 같음.
5. 1번재 숫자에 1을 더한 것은 마지막 숫자와 같음.

S의 1122-string인 서브 문자열 개수 구해라.
위치 다르면 숫자 같아도 다른 거임.
*/