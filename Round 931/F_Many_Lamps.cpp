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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n,m,k;
     cin>>n>>m>>k;
     vector<vl>adj(n+1);
     map<pll,ll>mp;
     rep(i,0,m){
          ll x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
          mp[{x,y}]=i+1;
          mp[{y,x}]=i+1;
     } 
     if(k%2){
          cout<<"No"<<endl;
          return;
     }
     vl subtree(n+1);
     vector<ll>vis(n+1);
     function<void(ll)> calc=[&](ll node)->void{
          vis[node]=1;
          subtree[node]=1;
          for(auto x:adj[node]){
               if(vis[x]) continue;
               calc(x);
               subtree[node]+=subtree[x];
          }
     };
     vl ans;
     function<void(ll,ll,ll)> dfs=[&](ll node,ll par,ll skip)->void{
          vis[node]=1;
          int ct=0;
          int ct2=0;
          for(auto x:adj[node]){
               if(vis[x]) continue;
               if(subtree[x]%2==0) ct2++;    
          }
          for(auto x:adj[node]){
               if(vis[x] and k<=0) continue;
               if(skip){
                    dfs(x,node,skip-1);
                    continue;
               }
               if(subtree[x]%2){
                    ans.pb(mp[{node,x}]);
                    k-=2;
                    dfs(x,node,1);
               }else{
                    dfs(x,node,0);
               }
          }
     };
     rep(i,1,n+1){
          if(!vis[i]){
               calc(i);
          }
     }
     vis.assign(n+1,0);
     rep(i,1,n+1){
          if(!vis[i]){
               dfs(i,-1,0);
          }
     }
     if(k!=0){
          cout<<"No"<<endl;
          return;
     }
     cout<<"Yes"<<endl;
     cout<<ans.size()<<endl;
     for(auto x:ans){
          cout<<x<<" ";
     }
     cout<<endl;
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