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

const int N=2e5+7;
vector<vl>adj(N);
ll n,m;

vector<bool> visited;
vector<ll> tin, low;
ll timer=0;
bool impossble=0;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                    impossble=1;
        }
    }
}

vector<pll>ans;
vector<ll>vis(N,0);
map<pll,ll>mp;
void mark(ll u, ll p=-1){
     vis[u]=1;
     for(auto v:adj[u]){
          if(!vis[v]){
               mp[{u,v}]=1;
               mark(v);
          }else{
               if(tin[v]>tin[u]){
                    mp[{v,u}]=1;
               }
          }
     }

}



void dk(){
     cin>>n>>m;
     vector<pll>vp;
     rep(i,0,m){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
          vp.pb({u,v});
     }
     
     tin.assign(n+1, -1);
     low.assign(n+1, -1);
     visited.assign(n+1, false);
     dfs(1);
     for (int i = 1; i <=n; ++i) {
          if (!visited[i])
              impossble=1;
     }
     if(impossble){
          cout<<0<<endl;
          return;
     }
     
     mark(1);

     for(auto it:vp){
          if(mp[{it.S,it.F}]){
               ans.pb({it.S,it.F});
          }else{
               ans.pb(it);
          }
     }
     for(auto it:ans){
          cout<<it.F<<" "<<it.S<<endl;
      }

     return;
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