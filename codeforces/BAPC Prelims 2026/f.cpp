#include "bits/stdc++.h"

using namespace std;
using ll = long long;
//using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

ll n, q[2020], idx=0, maxq;
string t[2020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(ll i = 0; i<n; i++){
        cin>>t[i]>>q[i];
        if(maxq<q[i]){
            idx=i;
            maxq=q[i];
        }
    }
    cout<<t[idx];
    return 0;
}