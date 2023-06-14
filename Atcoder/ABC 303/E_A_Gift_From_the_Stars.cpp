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
vector<vl> adj;
vl star;

ll dfs(ll u,ll p=0){
     ll ret=0;
     for(auto v: adj[u]){
          if(v==p) continue;
          ret=max(ret,dfs(v,u));
     }
     ret++;
     if(ret%3==2) star.pb(u);
     return ret;
}


void dk(){
     cin>>n;
     adj.resize(n+1); 
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     dfs(1);

     vl ans;
     for(auto it: star){
          ans.pb(adj[it].size());
     }

     sort(all(ans));
     for(auto it: ans){
          cout<<it<<" ";
     }
     cout<<endl;
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