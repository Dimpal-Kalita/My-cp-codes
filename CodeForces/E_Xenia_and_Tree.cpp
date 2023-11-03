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



class centroid_decomp{
     public:
     int n;
     vector<vector<int>>adj;
     vector<int> subtree,level,parent;
     centroid_decomp(int n,vector<vector<int>>adj){
          this->n=n; this->adj=adj;
          subtree.assign(n+1,0);
          level.assign(n+1,0);
          parent.assign(n+1,0);
     }
     int getSize(int node, int par=-1){
          subtree[node]=1;
          for(auto child:adj[node]){
               if(child==par or level[child]) continue;
               subtree[node]+=getSize(child,node);
          }
          return subtree[node];
     }
     int centroid(int node, int r, int par =-1){ // r is the size of current tree
          for(auto child:adj[node]){
               if(child==par or level[child]) continue;
               if(subtree[child]*2>r) return centroid(child,r,node);
          }
          return node;
     }
     int decompose(int node, int l,ll par=0){
          int cent=centroid(node,getSize(node));
          level[cent]=l;
          parent[cent]=par;
          for(auto child:adj[cent]){
               if(!level[child]) decompose(child,l+1,cent);
          }
          return cent;
     }

};


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



void dk(){
     ll n,q;
     cin>>n>>q;
     vector<vi>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     centroid_decomp cd(n,adj);
     cd.decompose(1,1);
     vi par=cd.parent,dist(n+1,1e9);

     LCA lca(n+1);
     lca.dfs(1,1,adj,0);



     
     auto update=[&](ll node){
          int cur=node;
          while(node){
               dist[node]=min(dist[node],lca.dist(node,cur));
               node=par[node];
          }
     };

     auto query=[&](ll node){
          int ans=dist[node],cur=node;
          while(node){
               ans=min(ans,dist[node]+lca.dist(node,cur));
               node=par[node];
          }
          return ans;
     };
     update(1);

     while(q--){
          ll t,u;
          cin>>t>>u;
          if(t==1){
               update(u);
          }else{
               cout<<query(u)<<endl;
          }
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