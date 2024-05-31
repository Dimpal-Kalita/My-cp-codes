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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n;
     cin>>n;
     vector<vl>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     } 
     vl v(n+1);
     rep(i,1,n+1) cin>>v[i];
     map<ll,pll> store;
     function<pll(ll,ll)> dfs=[&](ll node,ll parent)->pll{
          pll sum={0,0};
          for(auto x:adj[node]){
               if(x==parent) continue;
               pll cah=dfs(x,node);
               sum.F+=cah.F;
               sum.S+=cah.S;
          }
          store[node]={sum.S+sum.F,sum.S+v[node]};
          return store[node];
     };
     dfs(1,0);
     debug(store);
     ll ret=1e18;
     function<void(ll,ll,ll,ll)> dfs2=[&](ll node,ll parent,ll tot,ll sum)->void{
          ll ans=store[node].F+tot;
          cerr<<node<<" "<<ans<<endl;
          ret=min(ret,ans);
          sum+=store[node].S;
          sum-=v[node];
          for(auto x:adj[node]){
               if(x==parent) continue;
               cerr<<x<<" "<<node<<" "<<ans-store[x].S-store[x].F+sum-store[x].S<<" "<<sum<<endl;
               dfs2(x,node,ans-store[x].S-store[x].F+sum-store[x].S,sum+v[node]);
          }
          return;
     };
     dfs2(1,0,0,0);
     cout<<ret<<endl;
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