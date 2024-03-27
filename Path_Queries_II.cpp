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


template<bool VALS_EDGES> struct HLD {
     int N, tim = 0;
     vector<vi> adj;
     vi par, siz, depth, rt, pos;
     Node* tree;
     HLD(vector<vi> adj_):
          N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
          rt(N), pos(N), tree(new Node(0, N)) {
          dfsSz(0), dfsHld(0);
     }
     void dfsSz(int v) {
          if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
          for (int& u : adj[v]) {
               par[u] = v, depth[u] = depth[v] + 1;
               dfsSz(u);
               siz[v] += siz[u];
               if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
          }
     }
     void dfsHld(int v) {
          pos[v] = tim++;
          for (int u : adj[v]) {
               rt[u] = (u == adj[v][0] ? rt[v] : u);
               dfsHld(u);
          }
     }
     template<class B> void process(int u, int v, B op) {
          for (; rt[u] != rt[v]; v = par[rt[v]]) {
               if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
               op(pos[rt[v]], pos[v] + 1);
          }
          if (depth[u] > depth[v]) swap(u, v);
          op(pos[u] + VALS_EDGES, pos[v] + 1);
     }
     void modifyPath(int u, int v, int val) {
          process(u, v, [&](int l, int r) { tree->add(l, r, val); });
     } // tree->add is [inclusive, exclusive)     ^
     int queryPath(int u, int v) { // Modify depending on problem
          int res = -1e9;
          process(u, v, [&](int l, int r) { // inclusive,exclusive
               res = max(res, tree->query(l, r));
          });
          return res;
     }
     int querySubtree(int v) { // modifySubtree is similar
          return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
     }
};

void dk(){
      

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