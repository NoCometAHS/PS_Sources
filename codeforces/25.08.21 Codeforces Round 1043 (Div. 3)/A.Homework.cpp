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
        int n, m;
        string a, b, s;
        cin >> n >> a >> m >> b >> s; 
        
        reverse(b.begin(), b.end());
        for (auto& ch : s) {
            if (ch == 'D') {
                a += b.back();
                b.pop_back();
            }
            else {
                a = b.back() + a;
                b.pop_back();
            }
        }

        cout << a << '\n';
    }

    return 0;
}

/*
문자열 a, b

b로 부터 a로  문자
*/