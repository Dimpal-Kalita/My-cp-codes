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


ll n;
vector<vl>adj;
vector<pll>depth;
vl parent;

int dfs(ll node, ll par){
     depth[node].S = node;
     parent[node] = par;
     int mx=0;
     for(auto child: adj[node]){
          if(child!=par){
               mx=max(mx,dfs(child,node));
          }
     }
     depth[node].F=mx;
  return mx+1;
}

void dk(){
     cin>>n;
     adj.assign(n+1,{});
     depth.assign(n+1,{0,0});
     parent.assign(n+1,0);
     for(int i=1;i<n;i++){
         ll u,v;
         cin>>u>>v;
         adj[u].pb(v);
         adj[v].pb(u);
     }
     int mx=dfs(1,0);
     sort(all(depth));
     
     set<ll>lowdepth, temp;
     lowdepth.insert(1);
     for(auto i:adj[1]){
       lowdepth.insert(i);
     }
     temp=lowdepth;
     for(auto node:temp){
       for(auto i:adj[node]){
         lowdepth.insert(i);
       }
     }

     ll ans=0;
     for(int i=1;i<n;i++){
          if(lowdepth.count(depth[i].S)) continue;
          ll node=parent[depth[i].S];
          lowdepth.insert(node);
       
          ans++;
          for(auto i:adj[node]){
               lowdepth.insert(i);
          }
     }
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