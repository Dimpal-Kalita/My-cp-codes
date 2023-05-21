/**
 * 
 * author: Dimpal Kalita
 * date: 17/05/2023 21:05:52
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




vector<vector<int>> adj;


template<class T, class C = less<T>> struct RMQ {
     vector<vector<T>> t;
     C cmp;
     RMQ(vector<T>& a, C cmp = C{}):
          t(__lg(sz(a)) + 1, a), cmp(cmp) {
          for (int k = 1, len = 1; k < sz(t); k++, len <<= 1)
               for (int i = 0; i + 2 * len - 1 < sz(a); i++)
                    t[k][i] = min(t[k - 1][i], t[k - 1][i + len], cmp);
     }
     T query(int a, int b) { // inclusive-exclusive [a, b)
          int k = __lg(b - a), len = 1 << k;
          return min(t[k][a], t[k][b - len], cmp);
     }
};

struct LCA {
     int T = 0;
     vector<int> pre, inv, tour;
     vector<int> distance;
     RMQ<int> rmq;
     LCA(vector<vi>& adj, int root = 1):
          pre(sz(adj)), inv(pre),distance(sz(adj)), rmq((dfs(adj, root), tour)) {}
     void dfs(vector<vi>& adj, int u, int p = 0,int _distance=0) {
          inv[pre[u] = T++] = u;
          distance[u]=_distance;
          for (int v : adj[u])
               if (v != p) tour.push_back(pre[u]), dfs(adj, v, u,_distance+1);
     }
     int lca(int u, int v) {
          if (u == v) return u;
          tie(u, v) = minmax(pre[u], pre[v]);
          return inv[rmq.query(u, v)];
     }
     int dist(int u, int v) {
          return distance[u] + distance[v] - 2 * distance[lca(u, v)];
     }
};
void dk(){
     ll n, q;
     cin>>n>>q;
     adj.resize(n+2);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }

     LCA lca(adj,1);
     while(q--){
          ll k;
          cin>>k;
          vl v(k);
          inp(v);
          ll mx=v[0];
          for(auto x: v){
               if(lca.dist(x,v[0])>lca.dist(x,mx)){
                    mx=x;
               }
          }
          ll mx2=mx;
          for(auto x: v){
               if(lca.dist(x,mx2)>lca.dist(mx,mx2)){
                    mx=x;
               }
          }
          cout<<(lca.dist(mx2,mx)+1)/2<<endl;
     }
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