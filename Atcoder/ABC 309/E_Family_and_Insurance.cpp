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

ll n,m;
vector<vl>adj;
vl v;
vl vis;
ll dfs(ll u, ll val,ll par){
     ll ans=0;
     if(v[u]!=0) val=max(val,v[u]+1);
     if(val>0) ans++;
     vis[u]=1;
     for(auto x: adj[u]){
          if(u==par) continue;
          ans+=dfs(x,val-1,u);
     }
     return ans;
}

void dk(){
     cin>>n>>m;
     adj.resize(n+1);
     v.resize(n+1);
     vis.resize(n+1);
     rep(i,1,n){
          ll x;
          cin>>x;
          adj[x].pb(i+1);
     }
     rep(i,0,m){
          ll x,y;
          cin>>x>>y;
          v[x]=max(v[x],y);
     }
     ll ans=0;
     rep(i,1,n+1){
          if(!vis[i]){
               ans+=dfs(i,0,0);
          }
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