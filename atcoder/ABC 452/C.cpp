#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<iipair> ribs(n);
    for (auto& [a, b] : ribs) cin >> a >> b;

    int m;
    cin >> m;
    vector<string> arr(m);

    for (auto& i : arr) cin >> i;


    vector<vector<vector<bool>>> chk(11, vector<vector<bool>>(11, vector<bool>(26, false)));

    for (auto& str : arr) {
        int len = str.length();

        for (int i = 0; i < len; i++) {
            chk[len][i+1][str[i]-'a'] = true;
        }
    }

    for (auto& str : arr) {
        if (str.length() != n) {
            cout << "No\n";
        }
        else {

            bool pass = true;
            for (int i = 0; i < n; i++) {
                pass &= chk[ribs[i].first][ribs[i].second][str[i]-'a'];
            }

            if (pass) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}

/*
척추에 쓰인 문자열 길이가 N
각 갈비뼈에 쓰인 문자열 A_i

i번째 갈비뼈에 적힌 B_i번째 문자는 척추에 적힌 i번째 문자와 같다.

각 뼈에 적힌 문자열은 S_1 ~ S_m 사이, 중복 허용.

S는 모두 다른 영단어.

모든 S에 대해서 척추에 적힐 수 있냐?


*/