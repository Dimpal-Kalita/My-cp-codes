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


ll n,m;
vector<vl>adj;
map<pll,pll>mp;
vl vis;
vector<pll>ans;

void dfs(ll node){
     vis[node]=1;
     for(auto i:adj[node]){
          if(!vis[i]){
               ans[i]={ans[node].F+mp[{node,i}].F,ans[node].S+mp[{node,i}].S};
               dfs(i);
          }
     }
}

void dk(){
     cin>>n>>m;
     adj.resize(n+1);
     vis.resize(n+1);
     ans.resize(n+1,{-1,-1});
     rep(i,0,m){
          ll a,b,x,y;
          cin>>a>>b>>x>>y;
          adj[a].pb(b);
          adj[b].pb(a);
          mp[{a,b}]={x,y};
          mp[{b,a}]={-x,-y};
     }
     ans[1]={0,0};
     dfs(1);
     rep(i,1,n+1){
          if(!vis[i]){
               cout<<"undecidable"<<endl;
               continue;
          }
          cout<<ans[i].F<<" "<<ans[i].S<<endl;
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