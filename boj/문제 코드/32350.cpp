#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<int,int>;
using graphT = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d, p;
    cin >> n >> d >> p;

    int ans = 0;
    for (int i = 0, o = 0; i < n; i++) {
        int hp;
        cin >> hp;

        hp += o*p / 100;
        o = 0;
        
        if (hp > 0) {
            while (hp > 0){
                hp -= d;
                ans++;
            }

            o = hp;
        }
    }

    cout << ans;
 
    return 0;
}
