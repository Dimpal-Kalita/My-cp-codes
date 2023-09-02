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
     ll n;
     cin>>n;
     map<ll,vector<ll>>mp;
     rep(i,0,n){
          ll x,y;
          cin>>x>>y;
          mp[x].pb(y);
     } 
     vl v;
     ll ans=0;
     for(auto [x,y]:mp){
          sort(all(y),greater<ll>());
          v.pb(y[0]);
          if(y.size()>=2){
               ans=max(ans,y[0]+y[1]/2);
          }
     }
     sort(all(v),greater<ll>());
     if(v.size()>=2){
          ans=max(ans,v[0]+v[1]);
     }
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}