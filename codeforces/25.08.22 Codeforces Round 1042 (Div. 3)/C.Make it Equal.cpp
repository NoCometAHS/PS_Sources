#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        LL n, m;
        cin >> n >> m;

        multiset<LL> a, b;
        for (int i = 0; i < n; i++) {
            LL num;
            cin >> num;

            a.insert(num % m);
            a.insert(abs(num % m - m));
        }

        for (int i = 0; i < n; i++) {
            LL num;
            cin >> num;

            b.insert(num % m);
            b.insert(abs(num % m - m));
        }

        if (a == b) cout << "Yes\n";
        else cout << "No\n";
    }
        return 0;
}

//accepted
/*
크기 n인 멀티 셋 s, t. 양의 정수 k

마음대로 연산을 s에 적용.
s의 임의의 원소 x를 하나 지워. x+k 혹은 |x-k|를 추가해.

s, t가 같게 만들 수 있냐?

-----
원소가 1 대 1 대응 시킬 수 있느냐 인데?

모듈러?
k로 나눴을 때 나머지가 같으면 무조건 같게 만들 수 있는 거 아니냐?
-> 절대값때문에 힘들 듯. -> 음수로 만들고 절대값 씌운거에 k 빼보면 음수로 만들기 전 수 나오는 거 아님?
-> 음수로 만든 것까지 추가해서 같으면 같은 거 인 듯.



1 2 4, 4 3 1
3 4 1, 2 1 4
*/