/**
 * 
 * author: Dimpal Kalita
 * date: 15/05/2023 08:14:40
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

const int N= 2*1e5+7;
vector<vi> adj(N);
vector<ll> prefix(N), parent(N), ans(N);

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
     RMQ<int> rmq;
     LCA(vector<vi>& adj, int root = 0):
          pre(sz(adj)), inv(pre), rmq((dfs(adj, root), tour)) {}
     void dfs(vector<vi>& adj, int u, int p = 0) {
          inv[pre[u] = T++] = u;
          parent[u]=p;
          for (int v : adj[u])
               if (v != p) tour.push_back(pre[u]), dfs(adj, v, u);
     }
     int lca(int u, int v) {
          if (u == v) return u;
          tie(u, v) = minmax(pre[u], pre[v]);
          return inv[rmq.query(u, v)];
     }
};


ll dfs(int u, int p=0){

     ll sum=prefix[u];

     for(auto v:adj[u]){
          if(v==p) continue;
          sum+= dfs(v,u);
     }

     return ans[u]=sum;
}

void dk(){
      ll n,m;
      cin>>n>>m;
      rep(i,0,n-1){
          ll x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
      }
      LCA lca(adj,1);
      
      rep(i,0,m){
          ll u,v;
          cin>>u>>v;
          ll l= lca.lca(u,v);
          prefix[u]++;
          prefix[v]++;
          prefix[l]--;
          prefix[parent[l]]--;
      }
     //  rep(i,1,n+1){
     //      cout<<prefix[i]<<" ";
     //  }     
      dfs(1);
      rep(i,1,n+1){
          cout<<ans[i]<<" ";
      }
      cout<<endl;


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