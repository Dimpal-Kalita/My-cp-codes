/**
 * 
 * author: Dimpal Kalita
* 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


void dk(){
     vector<pll>v(3);
     rep(i,0,3){
          cin>>v[i].F>>v[i].S;
     }
     ll ans=1;

     ll val=0;
     if(v[1].F<v[0].F and v[2].F<v[0].F){
          val=min(abs(v[1].F-v[0].F),abs(v[2].F-v[0].F));
     }
     if(v[1].S<v[0].S and v[2].S<v[0].S){
          val+=min(abs(v[1].S-v[0].S),abs(v[2].S-v[0].S));
     }
     if(v[1].S>v[0].S and v[2].S>v[0].S){
          val+=min(abs(v[1].S-v[0].S),abs(v[2].S-v[0].S));
     }
     ll val2=0;
     if(v[1].F>v[0].F and v[2].F>v[0].F){
          val2=min(abs(v[1].F-v[0].F),abs(v[2].F-v[0].F));
     }
     if(v[1].S<v[0].S and v[2].S<v[0].S){
          val2+=min(abs(v[1].S-v[0].S),abs(v[2].S-v[0].S));
     }
     if(v[1].S>v[0].S and v[2].S>v[0].S){
          val2+=min(abs(v[1].S-v[0].S),abs(v[2].S-v[0].S));
     }
     ans=max(val,val2);
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}