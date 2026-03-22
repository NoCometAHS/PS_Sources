#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        if (n < 3) {
            cout << 1 << '\n';
        }
        else {
            cout << 3 << '\n';
        }
    }
    return 0;
}

/*
... 3 2 1

i가 3일때
...1 2 3
되고

나머지는 i와 2의 거듭제곱수와 스왑하니깐 3의 위치에 있는 1은 안 바뀌어
*/