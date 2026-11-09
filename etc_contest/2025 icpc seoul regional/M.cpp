#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using iipair = pair<ll,ll>;
ll n, ans[606];

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    if(n==1){
        for(ll i=0; i<3; i++){
            cout<<1<<' ';

        }
        return 0;
    }else if(n%3==2){
        for(ll i=0; i<3; i++){
            for(ll j=1; j<=n; j++){
                cout<<j<<' ';
            }
        }
        return 0;
    }
    
    for(ll i=1; i<=n; i++){
        
        ans[i]=i;
        
    }
    ll temp1 =2, temp2= 3, temp3=4;
    for(ll i=n+1; i<=2*n; i++){
        if(i%3==1){
            ans[i]=temp1;
            temp1+=3;
            if(temp1>n){
                temp1=3;
            }
        }else if(i%3==2){
            ans[i]=temp2;
            temp2+=3;
            if(temp2>n){
                temp2=1;
            }
        }else{
            ans[i]=temp3;
            temp3+=3;
            if(temp3>n){
                temp3=1;
            }
        }
    }
    for(ll i=n*2+1; i<=3*n; i++){
        if(i%3==1){
            ans[i]=temp1;
            temp1+=3;
            if(temp1>n){
                temp1=temp1%3;
            }
        }else if(i%3==2){
            ans[i]=temp2;
            temp2+=3;
            if(temp2>n){
                temp2=temp2%3;
            }
        }else{
            ans[i]=temp3;
            if(temp3==1){
                temp3=2;
            }else{
                temp3+=3;
                    if(temp3>n){
                        temp3=temp3%3;
                    }
            }
                
            
        }
    }
    for(ll i=1; i<=3*n; i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}