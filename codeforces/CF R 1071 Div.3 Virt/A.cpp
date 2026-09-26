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
        int k, x;
        cin >> k >> x;
        cout << k * x  + 1 << '\n';
    }
    return 0;
}

/*
j - i = x * d
d가 1일때만 생각하면 될 것 같은데

처음 x개만 보면 될 것 같은데?
나머지는 알아서 만들어지니깐


1 2 3 4 5 6 7 8 
a a a b b b c c

a a b b c c 

일단 n이 x-1까지는 k에 상관 없이 성립해.
 n이 x일때가 성립하려면 k가 2여야 하고,
 앞에서 쓴 걸 다시 쓰는 경우는 없을거야.

 ceil(n / x)만큼의 k가 필요한 것 같아.

 ceil(n / x) = k

 버리고 직 - 관
*/