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



class dfsTree{
     public:
          int n,root;
          vector<vector<int>>adj,graph,depIn,depOut;
          vector<int>dep,par,def;
          vector<pair<int,int>>bridge;

          dfsTree(int n,int root,vector<vector<int>>adj){
               this->n=n; this->adj=adj;
               this->root=root;
               graph.assign(n+1,vector<int>());
               depIn.assign(n+1,vector<int>());
               depOut.assign(n+1,vector<int>());
               dep.assign(n+1,0);
               par.assign(n+1,0);
               def.assign(n+1,0);
               dfs(root,root,1);
          }
          void dfs(int node, int p, int depth){
               dep[node]=depth;
               par[node]=p;
               for(auto child:adj[node]){
                    if(child==p) continue;
                    if(!dep[child]){
                         dfs(child,node,depth+1);
                         graph[node].pb(child);
                    }else{
                         if(dep[node]<dep[child]){
                              depIn[node].pb(child);
                              depOut[child].pb(node);
                         }
                    }
               }
          }

     private:
          void dfs2(int node,int p){ // setting up function for bridge
               def[node]= depOut[node].size()-depIn[node].size();
               for(auto child:graph[node]){
                    if(child==p) continue;
                    dfs2(child,node);
                    def[node]+=def[child];
               }
          }
          void get_bridge(int node,int p){
               if(node!=root and def[node]==0){
                    bridge.push_back({node,p});
               }
               for(auto child:graph[node]){
                    if(child==p) continue;
                    get_bridge(child,node);
               }
          }

};




bool isCyclic(int node,int p,vector<vector<int>>&adj,vector<int>&vis){
     vis[node]=1;
     for(auto child:adj[node]){
          if(child==p) continue;
          if(vis[child]) return true;
          if(isCyclic(child,node,adj,vis)) return true;
     }
     return false;
}

bool is_Cyclic(int n,vector<vi>&adj){
     vi vis(n+1,0);
     for(int i=1;i<=n;i++){
          if(!vis[i]){
               if(isCyclic(i,0,adj,vis)) return true;
          }
     }
     return false;
}
void dk(){
     int n,m;
     cin>>n>>m;
     vector<vector<int>>adj(n+1);
     vector<pll>vp;
     for(int i=0;i<m;i++){
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
          vp.pb({u,v});
     }

     dfsTree tree(n,1,adj);
     map<pll,ll>mp;
     vector<vi>graph(n+1);
     for(int i=1;i<=n;i++){
          for(auto x:tree.depOut[i]){
               mp[{i,x}]=1;
               mp[{x,i}]=1;
               graph[i].pb(x);
               graph[x].pb(i);
          }
          // cout<<i<<": ";
          for(auto x:tree.graph[i]){
               mp[{i,x}]=0;
               mp[{x,i}]=0;
               // cout<<x<<" ";
          }
          // cout<<endl;
     }
     // cout<<endl;
     if(!is_Cyclic(n,graph)){
          for(auto [u,v]:vp){
               cout<<mp[{u,v}];
          }
     }
     cout<<endl;
     return;
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