#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;

template<typename t>
using TwoVector = vector<vector<t>>;

vector<iipair> arr;
ll a[505050], b[505050], n, x;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        arr.push_back({a[i], i});
    }
    for(ll i=0; i<n; i++){
        cin>>b[i];
    }
    sort(arr.begin(), arr.end());
    ll l=0, r=(ll)1e14, wt=0;
    while(l<r){
        ll temp = (l+r)/2, cnt=0;
        for(ll i=0; i<n; i++){
            if(temp>arr[i].first){
                ll k=temp-arr[i].first;
                cnt+=k/b[arr[i].second];
                if(k%b[arr[i].second]){
                    cnt++;
                }
            }
        }
        if(cnt>x){
            r=temp;
        }else{
            wt=temp;
            l=temp+1;
        }
    }
    //cout<<wt<<'\n';
    priority_queue<iipair, vector<iipair>, greater<iipair>> pq;
    for(ll i=0; i<n; i++){
        if(wt<=a[i]){
            pq.push({a[i], i});
            continue;
        }
        ll k=wt-a[i];
        ll cnt=k/b[i];
        if(k%b[i]){
            cnt++;
        }
        x-=cnt;
        a[i]+=b[i]*cnt;
        pq.push({a[i], i});
    }                     
    while(x--){
        iipair tp = pq.top();
        pq.pop();
        tp.first+=b[tp.second];
        a[tp.second]+=b[tp.second];
        pq.push(tp);
    }
    for(ll i=0; i<n; i++){
        cout<<a[i]<<' ';
    }
    return 0;
}