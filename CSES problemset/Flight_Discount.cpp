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
     vector<vector<pll>>adj(n+1),adj2(n+1);
     rep(i,0,m){
          ll u,v,w;
          cin>>u>>v>>w;
          adj[u].pb({v,w});
          adj2[v].pb({u,w});
     }
     vl distu(n+1,1e18),distv(n+1,1e18);
     priority_queue<pll,vector<pll>,greater<pll>>pq;
     pq.push({0,1});
     distu[1]=0;
     while(!pq.empty()){
          ll u=pq.top().S;
          ll d=pq.top().F;
          pq.pop();
          if(d>distu[u]) continue;
          for(auto x: adj[u]){
               ll v=x.F;
               ll w=x.S;
               if(distu[v]>distu[u]+w){
                    pq.push({distu[v]=distu[u]+w,v});
               }
          }
     }

     pq.push({0,n});
     distv[n]=0;
     while(!pq.empty()){
          ll u=pq.top().S;
          ll d=pq.top().F;
          pq.pop();
          if(d>distv[u]) continue;
          for(auto x: adj2[u]){
               ll v=x.F;
               ll w=x.S;
               if(distv[v]>distv[u]+w){
                    pq.push({distv[v]=distv[u]+w,v});
               }
          }
     }
     
     ll ans=1e18;
     rep(u,1,n+1){
          for(auto [v,w]:adj[u]){
               ans=min(ans,distu[u]+distv[v]+w/2);
          }
     }
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