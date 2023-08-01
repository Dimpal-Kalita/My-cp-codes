/**
 * 
 * author: Dimpal Kalita
 * 
 */

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

int n,m,cycle_start,cycle_end;
vector<vi>adj;
vi vis,parent;
 
void dfs(int node){
     vis[node]=1;
     for(auto child:adj[node]){
          if(!vis[child]){
               parent[child]=node;
               dfs(child);
          }else if(vis[child]==1){
               cycle_start=node, cycle_end=child;
          }
     }
     vis[node]=2;
}
 
 
 
void dk(){
     cin>>n;
     adj.resize(n+1);
     vis.assign(n+1,0);
     parent.assign(n+1,-1);
     rep(i,0,n){
          int x;
          cin>>x;
          adj[i+1].pb(x);
     }
     rep(i,1,n+1){
          if(vis[i]) continue;
          cycle_start=-1,cycle_end=-1;
          dfs(i);
          if(cycle_start!=-1){
               vector<int>ans;
               int x=cycle_start;
               while(x!=cycle_end){
                    ans.pb(x);
                    x=parent[x];
               }
               reverse(all(ans));
 
               cout<<ans.size()+1<<endl;
               cout<<cycle_end<<" ";
               for(auto it:ans){
                    cout<<it<<" ";
               }
               
               return;
          }
 
     }
 
     cout<<"IMPOSSIBLE"<<endl;
}


int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}