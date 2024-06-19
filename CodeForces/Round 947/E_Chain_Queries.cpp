#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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
void dk(){
     ll n,q;
     cin>>n>>q;
     vector<vi> adj(n+1);
     vl col(n+1,0);
     rep(i,1,n+1) cin>>col[i];
     rep(i,0,n-1){
           int u,v;
           cin>>u>>v;
           adj[u].pb(v);
           adj[v].pb(u);
     }
     LCA lca(n+1);
     lca.dfs(1, 1, adj, 0);
     vl blackchild(n+1,0);
     vl parent(n+1,0);
     function<void(int,int)> dfs=[&](int u,int p){
         int ct=0;
         parent[u]=p;
         for(auto v:adj[u]){
             if(v==p) continue;
             dfs(v,u);
             ct+=(col[v]==1);
         }
         blackchild[u]=ct;
     };
     dfs(1,0); 
     set<ll>blackleaf;
     ll black=0;
     rep(i,1,n+1){
          if(col[i]==1 and blackchild[i]==0) blackleaf.insert(i);
          black+=col[i];
     }
     while(q--){
          ll node;
          cin>>node;
          if(col[node]==0){
               if(blackleaf.count(parent[node])){
                    blackleaf.erase(parent[node]);
               }
               blackchild[parent[node]]++;
               if(blackchild[node]==0) blackleaf.insert(node);
               black++;
               col[node]=1;
          }else{
               if(blackleaf.count(node)){
                    blackleaf.erase(node);
               }
               blackchild[parent[node]]--;
               if(blackchild[parent[node]]==0 and col[parent[node]]) blackleaf.insert(parent[node]);
               black--;
               col[node]=0;
          }
          if(blackleaf.size()>2 or black==0){
               cout<<"No"<<endl;
          }else if(blackleaf.size()==1){
               cout<<"Yes"<<endl;
          }else{
               ll u=*blackleaf.begin(),v=*blackleaf.rbegin();
               ll l=lca.lca(u,v);
               if(col[parent[l]]){
                    cout<<"No"<<endl; // since I am considering a straight chain consist of only one leaf
               }else if(lca.dist(u,v)+1==black){
                    cout<<"Yes"<<endl;
               }else{
                    cout<<"No"<<endl;
               }
          }
          // debug(blackleaf);
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