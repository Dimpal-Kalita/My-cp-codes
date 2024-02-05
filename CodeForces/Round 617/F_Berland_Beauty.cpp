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
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+1);
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
        int w = lca(u, v);
        return abs(distance[u] + distance[v] - 2*distance[w]);
    }
};

struct custom_hash {
    size_t operator()(pair<ll,ll>x) const {
          return hash<ll>()(x.first) ^ hash<ll>()(x.second);
    }
};

void dk(){
     ll n;
     cin>>n;
     vector<vector<pll>>adj(n+1); 
     vector<array<ll,2>> edge;
     for(int i=0;i<n-1;i++){
          ll u,v;
          cin>>u>>v;
          adj[u].pb({v,i});
          adj[v].pb({u,i});
     }
     vector<ll>ans(n-1);
     function<bool(ll,ll,ll,ll)> dfs=[&](ll u,ll p,ll dest,ll w){
          if(u==dest) return 1;
          for(auto [it,i]:adj[u]){
               if(it==p) continue;
               bool x =dfs(it,u,dest,w);
               if(x){
                    ans[i]=max(ans[i],w);
                    return 1;
               }
          }
          return 0;
     };

     vector<array<ll,3>> v;
     ll m;
     cin>>m;
     for(int i=1;i<=m;i++){
          ll x,y,w;
          cin>>x>>y>>w;
          v.pb({x,y,w});
          dfs(x,x,y,w);
     }
     function<ll(ll,ll,ll)> dfs2=[&](ll u,ll p,ll dest){
          ll ret=1e6;
          if(u==dest) return ret;

          for(auto [it,i]:adj[u]){
               if(it==p) continue;
               ll x=dfs2(it,u,dest);
               if(x){
                    return min(x,ans[i]);
               }
          }

          return 0LL;
     };
     for(auto [x,y,w]:v){
          ll z=dfs2(x,x,y);
          // cout<<x<<" "<<y<<" "<<w<<" "<<z<<endl;
          if(z!=w){
               cout<<-1<<endl;
               return;
          }
     }
     for(auto &it:ans){
          if(it==0) it=1e6;
          cout<<it<<" ";
     }
     cout<<endl;
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