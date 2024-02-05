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


struct LCA{
    vector<vector<ll>> up;
    vector<ll> tin, tout, distance,guard,dp;
    ll timer;
    ll N=20;
    LCA(ll n,vl v) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<ll>(N+1, -1));
        distance.assign(n, 0);
        dp.assign(n+1,0);
        this->guard=v;
    }
    void dfs(ll v, ll p, vector<vector<ll>> &adj, ll dis) {
        dp[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (ll i = 1; i < N+1; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (ll u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+guard[u]);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(ll u, ll v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    ll lca(ll u, ll v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (ll i = N; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    ll dist(ll u, ll v) {
        return dp[u]-dp[v];
    }
    ll calculate(ll u, ll x){
     for(ll i=N;i>=0;i--){
          ll d=dist(u,up[u][i]);
          if(d<x){
               x-=d;
               u=up[u][i];
          }
     }
     return u;
    }

};

void dk(){      
     ll n;
     cin>>n;
     vector<vl> adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     vl guard(n+1);
     rep(i,1,n+1){
          cin>>guard[i];
     }
     LCA lca(n+1,guard);
     lca.dfs(1,1,adj,guard[1]);
     ll q;
     cin>>q;
     while(q--){
          ll u,x;
          cin>>u>>x;
          cout<<lca.calculate(u,x)<<endl;
     }
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