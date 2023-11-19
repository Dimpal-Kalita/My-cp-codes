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
 
 
 
// class centroid_decomp{
//      public:
     ll n,k,ans=0,mx=0;
     vector<vector<int>>adj;
     vector<int> subtree,level,global;
     int getSize(int node, int par=-1){
          subtree[node]=1;
          for(auto child:adj[node]){
               if(child==par or level[child]) continue;
               subtree[node]+=getSize(child,node);
          }
          return subtree[node];
     }
     int centroid(int node, int r, int par =-1){
          for(auto child:adj[node]){
               if(child==par or level[child]) continue;
               if(subtree[child]*2>r) return centroid(child,r,node);
          }
          return node;
     }
     void dfs(int node, int par,int dist,bool flag){
          if(k<dist) return;
          if(flag) global[dist]++;
          else ans+=global[k-dist];
          mx=max(mx,(ll)dist);
          for(auto child:adj[node]){
               if(child==par or level[child]) continue;
               dfs(child,node,dist+1,flag);
          }
     }
 
     int decompose(int node, int l){
          int cent=centroid(node,getSize(node));
          level[cent]=l;
          mx=0;
          global[0]=1;
          vi tmp;
          for(auto child:adj[cent]){
               if(!level[child]){
                    dfs(child,cent,1,0);
                    dfs(child,cent,1,1);
                    tmp.pb(child);
               }
          }
          fill(global.begin(),global.begin()+mx+1,0);
          for(auto child:tmp){
                decompose(child,l+1);
          }
          return cent;
     }
// };
 
 
 
void dk(){
     cin>>n>>k;
     adj.assign(n+1,vi());
     subtree.assign(n+1,0);
     level.assign(n+1,0);
     global.assign(n+1,0);
     rep(i,0,n-1){
          int u,v; cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     decompose(1,1);
     cout<<ans<<endl;
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