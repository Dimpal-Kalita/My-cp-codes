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

// no constraint for distances
// statement should be more clear
// whether road means a direct edge between the cities or a path between them


void dk(){
     ll n,m;
     cin>>n>>m;
     vector<vector<pll>>adj1(n+1),adj2(n+1);
     rep(i,0,m){
          ll u,v,w1,w2;
          cin>>u>>v>>w1>>w2;
          adj1[u].pb({v,w1});
          adj1[v].pb({u,w1});
          if(w2>0){
                adj2[u].pb({v,w2});
                adj2[v].pb({u,w2});
          } 
     }
     ll s,d;
     cin>>s>>d;
     vector<vector<ll>>dist(n+1,vector<ll>(2,1e18));
     dist[s][0]=0;
     dist[s][1]=0;
     // array<ll,3>  = {distance,node, type2 used or not}
     priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>>pq;
     pq.push({0,s,0});
     while(!pq.empty()){
          auto [d,u,t]=pq.top();
          pq.pop();
          if(dist[u][t]<d) continue;
          if(t==0){
               for(auto [v,w]:adj2[u]){
                    if(dist[v][1]>dist[u][0]+w){
                         pq.push({dist[v][1]=dist[u][0]+w,v,1});
                    }
               }
          }

          for(auto [v,w]:adj1[u]){
               if(dist[v][t]>dist[u][t]+w){
                    pq.push({dist[v][t]=dist[u][t]+w,v,t});
               }
          }
     }
     if(s==d){
          cout<<"-1"<<endl;
          return;
     }
     if(dist[d][0]==1e18 && dist[d][1]==1e18) cout<<"-1"<<endl;
     else cout<<min(dist[d][0],dist[d][1])<<endl;
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