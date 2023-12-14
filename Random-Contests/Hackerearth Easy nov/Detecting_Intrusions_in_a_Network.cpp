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
    vector<vector<int>> up;
    vector<int> tin, tout, distance;
    int timer;
    LCA(int n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(21, -1));
        distance.assign(n, 0);
    }
    void dfs(int v, int p, vector<vector<int>> &adj, int dis) {
        distance[v]=(dis^=v);
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = 20; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        // cout<<distance[u]<<" ";  
        // cout<<distance[u]<<" ";  
        // cout<<distance[lca(u,v)]<<" ->";  
        return distance[u] ^ distance[v] ^ lca(u, v);
    }
};

void dk(){
     ll n;
     cin>>n;
     vector<vi>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
    LCA lca(n+1);
    lca.dfs(1,1,adj,0);
    ll q;
    cin>>q;
    while(q--){
        ll u,v,k;
        cin>>u>>v>>k;
        ll d=lca.dist(u,v);
        // cout<<d<<endl;
        if(d>k){
            cout<<"ALERT"<<endl;
        }else{
            cout<<"SECURE"<<endl;
        }
    }
}



int main()
{ 
    fast_io;
    
    int _=1;
    // cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   