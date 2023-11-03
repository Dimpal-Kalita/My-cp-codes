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


vl cost;

struct LCA{
    vector<vector<int>> up;
    vector<int> tin, tout, distance;
    int timer;
    vector<vector<int>>store;
    LCA(int n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(21, -1));
        distance.assign(n, 0);
        store.assign(n,{});
    }
    void dfs(int v, int p, vector<vector<int>> &adj, int dis,vector<int>count) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];

        for(int i=0;i<30;i++){
          if(cost[v]&(1<<i)) count[i]++;
        }
        store[v]=count;
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+1,count);
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

ll n,q;
vector<vi>adj;

void dk(){
     cin>>n>>q;
     adj.assign(n+1,{});
     cost.assign(n+1,0);
     rep(i,0,n-1){
           ll u,v;
           cin>>u>>v;
           adj[u].pb(v);
           adj[v].pb(u);
     }
     rep(i,1,n+1){
          cin>>cost[i];
     }
     LCA lca(n+1);
     vi count(31,0);
     lca.dfs(1,1,adj,0,count);
     while(q--){
          ll u,v;
          cin>>u>>v;
          ll ans=0;
          vi count1=lca.store[u];
          vi count2=lca.store[v];
          vi l=lca.store[lca.lca(u,v)];
          ll lc=lca.lca(u,v);
          rep(i,0,31){
               ll temp=count1[i]+count2[i]-2*l[i];
               if(cost[lc]&(1<<i)){
                    temp++;
               }
               if(temp%2==1){
                    ans+=(1<<i);
               }
               if(temp){
                    ans+=(1<<i);
               } 
          }
          cout<<ans<<endl;
     }
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