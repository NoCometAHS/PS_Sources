#include "bits/stdc++.h"

using namespace std;
using ll = long long;
//using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

ll n, x, y, l, r, k;

ll gcdo(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>x>>y;
    l=(y-1)*x;
    r=x-1;
    k=gcdo(l, r);          
    cout<<(l/k)+(r/k);
    return 0;
}