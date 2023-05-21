/**
 * 
 * author: Dimpal Kalita
 * date: 26/04/2023 00:45:46
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


const int N=2e5+7;
vector<pll> adj[N];


ll dfs(ll node, ll par){
     
}



void dk(){
     ll n;
     cin>>n;
     rep(i,0,n-1){
          ll u, v, w;
          cin>>u>>v>>w;
          adj[u].pb({v,w});
          adj[v].pb({u,w});
     }



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