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
     ll n,m,k,s,e;
     cin>>n>>m>>k>>s>>e; 
     vector<vector<pll>> adj(n+1);
     rep(i,0,m){
          ll u,v,w=1;
          cin>>u>>v;
          adj[u].pb({v,w});
          adj[v].pb({u,w});
     }
     rep(i,0,k){
          ll u,v,w=2;
          cin>>u>>v;
          adj[u].pb({v,w});
          adj[v].pb({u,w});
     }
     vector<ll> dist(n+1,1e18);
     dist[s]=0;
     priority_queue<pll,vector<pll>,greater<pll>> pq;
     pq.push({0,s});
     while(!pq.empty()){
          ll u=pq.top().S;
          ll d=pq.top().F;
          pq.pop();
          if(d>dist[u]) continue;
          for(auto x: adj[u]){
               ll v=x.F;
               ll w=x.S;
               if(dist[v]>dist[u]+w){
                    pq.push({dist[v]=dist[u]+w,v});
               }
          }
     }
     if(dist[e]==1e18) cout<<-1<<endl;
     else cout<<dist[e]<<endl;
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