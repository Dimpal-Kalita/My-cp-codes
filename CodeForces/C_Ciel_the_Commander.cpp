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
     vector<int> subtree,level;
     centroid_decomp(int n,vector<vector<int>>adj){
          this->n=n; this->adj=adj;
          subtree.assign(n+1,0);
          level.assign(n+1,0);
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
     int decompose(int node, int l){
          int cent=centroid(node,getSize(node));
          level[cent]=l;
          for(auto child:adj[cent]){
               if(!level[child]) decompose(child,l+1);
          }
          return cent;
     }

};

void dk(){
     ll n;
     cin>>n;
     vector<vector<int>>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     centroid_decomp cd(n,adj);
     cd.decompose(1,1);
     for(int i=1;i<=n;i++){
          cout<<(char)(cd.level[i]+'A'-1)<<" ";
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