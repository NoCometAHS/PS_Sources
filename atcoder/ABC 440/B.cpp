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

    priority_queue<iipair, vector<iipair>, greater<iipair>> pq;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        
        pq.push({num, i});
    }


    for (int i = 0; i < 3; i++) {
        cout << pq.top().second << ' ';
        pq.pop();
    }

    return 0;
}
