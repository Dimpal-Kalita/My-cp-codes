/**
 * 
 * author: Dimpal Kalita
 * date: 18/05/2023 19:42:33
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (ll)(x).size()   
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




template<class T>
pair<vector<T>, vector<T>> dijkstra(
     const vector<vector<pair<T, T>>>& adj, int s) {
     using ST = pair<T, T>;
     priority_queue<ST, vector<ST>, greater<ST>> q;
     vector<T> dist(adj.size());
     vector<bool> seen(adj.size());
     vector<T> par(adj.size());
     q.emplace(T{}, s);
     seen[s] = 1;
     while (!q.empty()) {
          auto [d, u] = q.top();
          q.pop();
          if (dist[u] < d) continue;
          for (auto [v, w] : adj[u])
               if (!seen[v] || d + w < dist[v]) {
                    q.emplace(dist[v] = d + w, v);
                    par[v]=u;
                    seen[v] = 1;
               }
     }
     return {dist,par};
}

void dk(){
      ll n,m,k;
      cin>>n>>m>>k;
      vector<vector<pll>> adj(n+1);
      map<pll,ll> mp;
      rep(i,0,m){
          ll u,v,w;
          cin>>u>>v>>w;
          mp[{u,v}]=i+1;
          mp[{v,u}]=i+1;
          adj[u].pb({v,w});
          adj[v].pb({u,w});
      }

      auto [dist, par]= dijkstra(adj,1);
      
      vl ans;
      queue<ll> q;
      q.push(1);
      while(!q.empty()){
          ll u=q.front();
          q.pop();
          for(auto [v,w]:adj[u]){
               if(par[v]==u){
                    ans.pb(mp[{u,v}]);
                    q.push(v);
               }
          }
      }
      
      cout<<min(k,sz(ans))<<endl;
      for(int i=0;i<min(k,sz(ans));i++){
          cout<<ans[i]<<" ";
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