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
     ll n,x;
     cin>>n>>x;
     ll N=1;
     vector<pll>vp;
     rep(i,0,n){
          ll u,v;
          cin>>u>>v;
          vp.pb({u,v});
          N+=v;
     } 
     vl dp(N,1e12);
     dp[0]=0;
     ll ans=0;
     for(int i=0;i<n;i++){
          vl ndp=dp;
          ll cur=x*i;
          for(int j=0;j<N;j++){
             if(dp[j]+vp[i].F<=cur) {
                 ndp[j+vp[i].S]=min(ndp[j+vp[i].S],dp[j]+vp[i].F);
                 ans=max(ans,(ll)j+vp[i].S);
             }
          }
          dp=ndp;
     }
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   