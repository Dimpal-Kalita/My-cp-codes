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
               dfs(root,1,1);
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



void dk(){
     ll n,m;
     cin>>n>>m;
     vector<vector<int>>adj(n+1); 
     vector<pll>vp;
     rep(i,0,m){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
          vp.pb({u,v});
     }
     dfsTree dt(n,1,adj); 
     if(sz(dt.bridge)>0){
          cout<<0<<endl;
          return;
     }
     map<pll,ll>mp;
     for(int i=1;i<=n;i++){
          for(auto c:dt.depOut[i]){
               mp[{i,c}]=1;
               mp[{c,i}]=-1;
          }
          for(auto c:dt.graph[i]){
               mp[{i,c}]=1;
               mp[{c,i}]=-1;
          }
     }
     for(auto [u,v]:vp){
          if(mp[{u,v}]==-1) swap(u,v);
          cout<<u<<" "<<v<<endl;
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