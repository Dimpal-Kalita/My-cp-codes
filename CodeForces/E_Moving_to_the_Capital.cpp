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
     vector<vl>adj(n+1);
     rep(i,0,m){
           ll u,v;
           cin>>u>>v;
           adj[u].pb(v);
     }
     vl dis(n+1,1e18);
     dis[1]=0;
     priority_queue<pll,vector<pll>,greater<pll>>pq;
     pq.push({0,1});
     while(!pq.empty()){
           ll u=pq.top().S;
           ll d=pq.top().F;
           pq.pop();
           if(d>dis[u]) continue;
           for(auto v:adj[u]){
                 if(dis[v]>dis[u]+1){
                       pq.push({dis[v]=dis[u]+1,v});
                 }
           }
     }
     vector<vector<pll>>graph(n+1);
     map<ll,vl>mp;
     rep(i,1,n+1){
           for(auto v:adj[i]){
                 if(dis[i]<dis[v]){
                       graph[v].pb({i,0});
                 }else{
                       graph[v].pb({i,1});
                 }
           }
           mp[dis[i]].pb(i);
     }

     vector<vl>dp(n+1,vl(2,1e18));
     rep(dist,0,n+1){
          if(mp[dist].empty()) continue;
          queue<pll>q;
          for(auto x:mp[dist]){
               q.push({x,0});
          }
          while(!q.empty()){
                ll u=q.front().F;
                ll d=q.front().S;
                q.pop();
                for(auto v:graph[u]){
                    if(d+v.S>1 || min({dp[v.F][0],dp[v.F][1]})!=1e18) continue;
                    dp[v.F][d]=dist;
                    q.push({v.F,d+v.S});
                }
          }
     }
     rep(i,1,n+1){
          cout<<min({dp[i][0],dp[i][1],dis[i]})<<" ";
     }
     cout<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   