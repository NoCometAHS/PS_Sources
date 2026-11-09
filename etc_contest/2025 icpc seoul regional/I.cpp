#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

ll n, q, l, r, y;
vector<ll> lvt, rvt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(ll i=0; i<n; i++){
        cin>>l>>r>>y;
        lvt.push_back(l);
        rvt.push_back(r);
    }
    sort(lvt.begin(), lvt.end());
    sort(rvt.begin(), rvt.end());
    while(q--){
        cin>>y;
        ll ans=0;
        if(y<lvt[n-1]){
            ans=max(lvt[n-1]-y, ans);
        }
        if(rvt[0]<y){
            ans=max(y-rvt[0], ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}