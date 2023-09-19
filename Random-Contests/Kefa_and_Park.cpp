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
ll dfs(ll u, ll p, ll ct){
          ll ans=0;
          if(v[u]) ct++;
          else ct=0;
          if(ct>m) return 0;
          if(adj[u].size()==1 && u!=1) return 1;
          for(auto v: adj[u]){
               if(v!=p){
                    ans+=dfs(v,u,ct);
               }
          }
          return ans;
}

void dk(){
     cin>>n>>m;
     adj.resize(n+1);
     v.resize(n+1);
     rep(i,1,n+1) cin>>v[i];
     rep(i,0,n-1){
           ll u,v;
           cin>>u>>v;
           adj[u].pb(v);
           adj[v].pb(u);
     }
     cout<<dfs(1,0,0)<<endl;
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