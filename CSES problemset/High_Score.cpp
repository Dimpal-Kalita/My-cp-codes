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
 
 
void dk(){
     ll n,m;
     cin>>n>>m;
     vector<vector<ll>> adj(n+1);
     vector<pair<ll,pll>> edges;
     rep(i,0,m){
         ll u,v,w;
         cin>>u>>v>>w;
         adj[u].pb(v);
         edges.pb({u,{v,w}});
     }
     vector<ll> dist(n+1,LLONG_MIN);
     dist[1]=0;
     for(int i=1;i<n;i++){
           for(auto [u,y]: edges){
               ll w=y.S,v=y.F;
               if(dist[u]!=LLONG_MIN && dist[u]+w>dist[v]){
                    dist[v]=dist[u]+w;
               }
           }
     }
     queue<ll>q;
     q.push(1);
     vector<bool> vis(n+1,false);
     vector<ll>reachable;
     while(!q.empty()){
          ll u=q.front();
          q.pop();
          if(vis[u]) continue;
          vis[u]=true;
          for(auto v: adj[u]){
               if(!vis[v]){
                    reachable.pb(v);
                    q.push(v);
               }
          }
     }
 
 
     reachable.pb(1);
     map<ll,ll>mp;
 
     for(auto i:reachable){
          queue<ll>q2;
          vector<bool> vis2(n+1,false);
          q2.push(i);
          while(!q2.empty()){
               ll u=q2.front();
               q2.pop();
               if(vis2[u]) continue;
               vis2[u]=true;
               for(auto v: adj[u]){
                    if(!vis2[v]){
                         q2.push(v);
                    }
               }
          }
          if(vis2[n]){
               mp[i]++;
          }
     }
 
     
     for(auto [u,y]: edges){
          ll w=y.S,v=y.F;
          if(dist[u]!=LLONG_MIN && dist[u]+w>dist[v] and mp[v]){
               cout<<-1<<endl;
               return;
          }
 
     }
 
     cout<<dist[n]<<endl;
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