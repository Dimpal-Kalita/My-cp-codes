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


void dk(){
     ll n,m;
     cin>>n>>m;
     vector<vl> adj(n+1);
     rep(i,0,m){
          vl v(n);
          inp(v);
          rep(i,2,n){
               adj[v[i-1]].pb(v[i]);
          } 
     }
     vector<ll>vis(n+1);
     bool cycle=0;
     function<void(ll)> dfs=[&](ll node)->void{
          vis[node]=1;
          for(auto it:adj[node]){
               if(vis[it]==0) dfs(it);
               else if(vis[it]==1) cycle=1;
          }
          vis[node]=2;
     };
     rep(i,1,n+1){
          if(!vis[i]){
               dfs(i);
          }
     }
     cout<<(cycle==0?"YES":"NO")<<endl;
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