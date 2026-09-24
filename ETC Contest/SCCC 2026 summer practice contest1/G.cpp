#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    set<int> Em, Ma;

    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        Em.insert(d);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int d;
        cin >> d;
        Ma.insert(d);
    }

    int ans = 0;
    bool EmLove = false, MaLove = false;;
    for (int i = 0; i < 1000000; i++) {
        bool em = Em.count(i), ma = Ma.count(i);
        
        if (em && ma) {
            ans++;
            EmLove = MaLove = false;
        }
        else if (em && !ma) {
            if (EmLove) continue;

            ans++;
            EmLove = true;
            MaLove = false;
        }
        else if (!em && ma) {
            if (MaLove) continue;

            ans++;
            EmLove = false;
            MaLove = true;
        }

    }

    cout << ans;
    
    return 0;
}