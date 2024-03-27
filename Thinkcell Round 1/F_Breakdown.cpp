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
     ll n,m;
     cin>>n>>m;
     vector<vl>adj(n+1);
     vector<pll>vp;
     rep(i,0,m){
         ll a,b;
         cin>>a>>b;
         vp.pb({a,b});
     }
     vector<pii> v(n+1);
     rep(i,1,n+1){
         cin>>v[i].F;
     }
     rep(i,1,n+1){
         cin>>v[i].S;
     }
     for(auto i:vp){
          if(v[i.F].F>v[i.S].F){
               adj[i.F].pb(i.S);
          }
          if(v[i.S].F>v[i.F].F){
               adj[i.S].pb(i.F);
          }
     }
     vl dp2(n+1,-1);
     function<ll(ll)> dfs=[&](ll u){
          if(dp2[u]!=-1) return dp2[u];
          ll s=adj[u].size();
          vector<vl>dp(v[u].F+1,vl(s+1,0));
          ll ans=0;
          for(int i=0;i<adj[u].size();i++){
               ll cc=dfs(adj[u][i]);
               for(int j=0;j<v[u].F;j++){
                    if(j<v[adj[u][i]].F){
                         dp[j][i+1]=dp[j][i];
                    }else{
                         dp[j][i+1]=max(dp[j][i],dp[j-v[adj[u][i]].F][i]+cc);
                    }
                    ans=max(ans,dp[j][i+1]);
               }
          }
          return dp2[u]=ans+1;
     };
     ll ans=0;
     for(int i=1;i<=n;i++){
          ll x=dfs(i);
          ans+=x*v[i].S;
     }
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   