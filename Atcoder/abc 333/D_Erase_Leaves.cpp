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
     ll n;
     cin>>n;
     vector<vl>adj(n+1);
     rep(i,0,n-1){
         ll x,y;
         cin>>x>>y;
         adj[x].pb(y);
         adj[y].pb(x);
     }
     vl subtree(n+1,0);

     function<void(ll,ll)>dfs=[&](ll u,ll p){
         subtree[u]=1;
         for(auto v:adj[u]){
             if(v!=p){
                 dfs(v,u);
                 subtree[u]+=subtree[v];
             }
         }
     };
     dfs(1,0);

     vl v;
     for(auto i:adj[1]){
           v.pb(subtree[i]);
     }
     sort(all(v));
     ll ans=accumulate(all(v),0LL)-v.back()+1;
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