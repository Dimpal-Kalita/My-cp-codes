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




ll max_distance( vector<vector<pair<int,ll>>> &adj, int s,vector<int>&vis) {
     ll mx=0;
     vis[s]=1;
     for(auto i:adj[s]){
          if(!vis[i.F]){
               mx=max(mx,max_distance(adj,i.F,vis)+i.S);
          }
     }
     vis[s]=0;
     return mx;
}

void dk(){
      ll n,m;
      cin>>n>>m;
      vector<vector<pair<int,ll>>>adj(n+1);
      rep(i,0,m){
           int x,y;
           ll w;
           cin>>x>>y>>w;
           adj[x].pb({y,w});
           adj[y].pb({x,w});
      }
      ll mx=0;
      rep(i,1,n+1){
          vector<int>vis(n+1,0);
          mx=max(mx,max_distance(adj,i,vis));
      }
      cout<<mx<<endl;
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