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
        string str;
        cin >> str;

        iipair pos; int num = 1e9;

        for (int i = str.length()-1; i >= 0; i--) {
            for (int k = str.length()-1; k > i; k--) {
                if (str[i] >= str[k]) continue;

                if (num < str[k]) continue;
                num = str[k];
                pos = {i, k};
            }

            if (num != 1e9) break;
        }

        if (num == 1e9) cout << "BIGGEST\n";
        else {
            swap(str[pos.first], str[pos.second]);
            sort(str.begin() + pos.first + 1, str.end());

            cout << str << '\n';
        }
    }
    return 0;
}

/*
이미 있는 수들의 자리를 바꿔가며 찾아야함.

수들이 내림차순 정렬되어 있으면 다음 수 없음.

브포는 안 됨.

최대한 작은 자리수끼리 바뀌어야함.

여러개의 수들이 움직여

다음 수가 있다는 건 (앞자리수 < 뒷자리수)인 어떤 쌍이 있다는 것.
바뀌게된 앞 자리수의 뒤의 수들은 오름차순 정렬해야지 작아지잖아.

모든 쌍을 살펴보데, 바뀌는 앞자리수가 가장 작고, 바꾸는 수도 가장 작은 한 쌍을 찾자.
*/