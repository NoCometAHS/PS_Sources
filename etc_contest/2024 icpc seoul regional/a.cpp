#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

ll n, m;
ll arr[101][303];

ll ans[202], tp[202];
priority_queue<iipair, vector<iipair>, greater<iipair>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    ans[0]=tp[0]=n;
    for(ll i=0; i<n; i++){
        ll tot=0;
        for(ll j=0; j<m; j++){
            pq.push({tot+arr[i][j], j});
            tot+=arr[i][j];
        }
    }
    queue<ll> q;
    while(!pq.empty()){
        ll idx=pq.top().second;
        ll tm=pq.top().first;
        pq.pop();
        while(!pq.empty()&&tm==pq.top().first){
            tp[pq.top().second+1]++;
            tp[pq.top().second]--;
            q.push(pq.top().second);
            pq.pop();
        }
        tp[idx+1]++;
        tp[idx]--;
        q.push(idx);
        //cout<<tp[idx+1]<<'\n';
        while(!q.empty()){
            idx=q.front();
            ans[idx]=max(tp[idx], ans[idx]);
            ans[idx+1]=max(tp[idx+1], ans[idx+1]);
            q.pop();
        }
    }
    for(ll i=0; i<m; i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}