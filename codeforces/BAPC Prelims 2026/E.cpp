#include "bits/stdc++.h"

using namespace std;
using ll = long long;
//using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

ll n, arr[101010], ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(ll i=0; i<n; i++){
        ans=max(ans, arr[i]*(n-i));
    }
    cout<<ans;
    return 0;
}