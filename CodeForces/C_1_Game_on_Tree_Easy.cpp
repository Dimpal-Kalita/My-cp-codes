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


void dk(){
     ll n,t;
     cin>>n>>t;
     vector<vl>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     function<ll(ll,ll)>dfs=[&](ll node, ll par)->ll{
          ll ans=0;
          for(auto x:adj[node]){
               if(x==par) continue;
               ans=dfs(x,node);
          }
          return ans+1;
     };
     ll node;
     cin>>node;
     vl tt;
     for(auto x:adj[node]){
          tt.pb(dfs(x,node));
     }
     for(auto i:tt){
          if(i%2){
               cout<<"Ron"<<endl;
               return;
          }
     }
     cout<<"Hermione"<<endl;
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