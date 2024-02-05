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


struct Dinic {
     struct Edge {
          int to, rev;
          ll c, oc;
          ll flow() { return max(oc - c, 0LL); } // if you need flows
     };
     vi lvl, ptr, q;
     vector<vector<Edge>> adj;
     Dinic(int n): lvl(n), ptr(n), q(n), adj(n) {}
     void addEdge(int a, int b, ll c, ll rcap = 0) {
          adj[a].push_back({b, sz(adj[b]), c, c});
          adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
     }
     ll dfs(int v, int t, ll f) {
          if (v == t || !f) return f;
          for (int& i = ptr[v]; i < sz(adj[v]); i++) {
               Edge& e = adj[v][i];
               if (lvl[e.to] == lvl[v] + 1)
                    if (ll p = dfs(e.to, t, min(f, e.c))) {
                         e.c -= p, adj[e.to][e.rev].c += p;
                         return p;
                    }
          }
          return 0;
     }
     ll calc(int s, int t) {
          ll flow = 0;
          q[0] = s;
          rep(L, 0,
               31) do { // 'int L=30' maybe faster for random data
               lvl = ptr = vi(sz(q));
               int qi = 0, qe = lvl[s] = 1;
               while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e : adj[v])
                         if (!lvl[e.to] && e.c >> (30 - L))
                              q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
               }
               while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
          }
          while (lvl[t])
               ;
          return flow;
     }
     bool leftOfMinCut(int a) { return lvl[a] != 0; }
};


vector<pll>dxy={{-1,0},{0,-1},{1,0},{0,1}};
void dk(){
      ll n,m;
      cin>>n>>m;
      vector<vl>v(n,vl(m));
      rep(i,0,n){
           rep(j,0,m){
                cin>>v[i][j];
           }
      }
      Dinic d(n*m+n*m+2);
      ll s=n*m;
      rep(i,0,n){
           rep(j,0,m){
               ll nx=s+i*m+j;
               // cout<<i*m+j<<" "<<nx<<" "<<v[i][j]<<endl;
               d.addEdge(i*m+j,nx,v[i][j]);
               for(auto [dx,dy]:dxy){
                    ll x=i+dx,y=j+dy;
                    if(x<0 or y<0 or x>=n or y>=m) continue;
                    ll ny=m*x+y;
                    // cout<<nx<<" "<<ny<<" "<<10000000<<endl;
                    d.addEdge(nx,ny,1e8);
               }
           }
      }
      cout<<d.calc(s,n*m-1)<<endl;
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