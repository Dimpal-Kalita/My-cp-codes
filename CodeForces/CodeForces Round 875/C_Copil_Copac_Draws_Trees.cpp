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
map<pll,ll> mp;
ll max_depth(ll u, ll p=0){

     ll mx=0;
     for(auto v:adj[u]){
          if(v!=p){
              if(p==0) mx=max(mx,max_depth(v,u));
              else{
                    if(mp[{u,v}]<mp[{u,p}]) mx=max(mx,max_depth(v,u)+1);
                    else mx=max(mx,max_depth(v,u));
              }
          }
     }
     return mx;
}

void dk(){
     cin>>n;
     adj.assign(n+1,vl());
     mp.clear();
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
          mp[{u,v}]=mp[{v,u}]=i;
     }
     cout<<max_depth(1)+1<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}