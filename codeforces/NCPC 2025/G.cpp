#include "bits/stdc++.h"

using namespace std;
using ll = long long;
//using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

vector<ll> vt[101010];
bool can=true;
ll n, m, k, a, b;

ll chk[101010];

ll bfs(ll now){
    chk[now]=1;
    ll cnt=1;
    queue<ll> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(ll temp: vt[now]){
            if(!chk[temp]){
                cnt++;
                chk[temp]=(cnt-1)%k+1;
                q.push(temp);
            }
        }
    }
    return cnt;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(ll i=0; i<m; i++){
        cin>>a>>b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    for(ll i=1; i<=n; i++){
        if(!chk[i]){
            ll temp=bfs(i);
            //cout<<temp<<'\n';
            if(temp<k){
                can=false;
            }
        }
    }
    if(can){
        for(ll i=1; i<=n; i++){
            cout<<chk[i]<<' ';
        }
    }else{
        cout<<"impossible";
    }
    return 0;
}

