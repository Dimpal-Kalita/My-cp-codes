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

// https://codeforces.com/blog/entry/75885

// https://codeforces.com/blog/entry/75885
struct SplayTree {
     struct Node {
          int ch[2] = {0, 0}, p = 0, cnt = 1;
          ll self = 0, path = 0; // Path aggregates
          ll sub = 0, vir = 0; // Subtree aggregates
          bool flip = 0; // Lazy tags
     };
     vector<Node> T;
     SplayTree(int n): T(n + 1) { T[0].cnt = 0; }
     void push(int x) {
          if (!x || !T[x].flip) return;
          int l = T[x].ch[0], r = T[x].ch[1];
          T[l].flip ^= 1, T[r].flip ^= 1;
          swap(T[x].ch[0], T[x].ch[1]);
          T[x].flip = 0;
     }
     void pull(int x) {
          int l = T[x].ch[0], r = T[x].ch[1];
          push(l);
          push(r);
          T[x].path = T[l].path + T[x].self + T[r].path;
          T[x].sub = T[x].vir + T[l].sub + T[r].sub + T[x].self;
          T[x].cnt = T[l].cnt + 1 + T[r].cnt;
     }
     void set(int x, int d, int y) {
          T[x].ch[d] = y;
          T[y].p = x;
          pull(x);
     }
     void splay(int x) {
          auto dir = [&](int x) {
               int p = T[x].p;
               if (!p) return -1;
               return T[p].ch[0] == x ? 0 : T[p].ch[1] == x ? 1 : -1;
          };
          auto rotate = [&](int x) {
               int y = T[x].p, z = T[y].p, dx = dir(x), dy = dir(y);
               set(y, dx, T[x].ch[!dx]);
               set(x, !dx, y);
               if (~dy) set(z, dy, x);
               T[x].p = z;
          };
          for (push(x); ~dir(x);) {
               int y = T[x].p, z = T[y].p;
               push(z);
               push(y);
               push(x);
               int dx = dir(x), dy = dir(y);
               if (~dy) rotate(dx != dy ? x : y);
               rotate(x);
          }
     }
     // TEST THIS STUFF
     int kth(int x, int k) {
          if (!x) return 0;
          k = min(max(k, 0), T[x].cnt - 1);
          for (int l = T[x].ch[0]; T[l].cnt != k; l = T[x].cnt)
               if (T[l].cnt < k) x = l;
               else k -= T[l].cnt + 1, x = T[x].ch[1];
          return splay(x), x;
     }
     // k = size of left subtree
     pair<int, int> split(int x, int k) {
          if (!x || k <= 0) return {0, x};
          if (k >= T[x].cnt) return {x, 0};
          int r = kth(x, k), l = T[r].ch[0];
          T[r].ch[0] = 0, T[l].p = 0;
          return {l, r};
     }
     int merge(int l, int r) {
          if (!l || !r) return !l ? r : l;
          r = kth(r, 0), set(r, 0, l);
          return r;
     }
};

struct LinkCut: SplayTree {
     LinkCut(int n): SplayTree(n) {}
     int access(int x) {
          int u = x, v = 0;
          for (; u; v = u, u = T[u].p) {
               splay(u);
               int& ov = T[u].ch[1];
               T[u].vir += T[ov].sub;
               T[u].vir -= T[v].sub;
               ov = v;
               pull(u);
          }
          return splay(x), v;
     }
     void reroot(int x) {
          access(x);
          T[x].flip ^= 1;
          push(x);
     }
     void Link(int u, int v) {
          reroot(u), access(v);
          T[v].vir += T[u].sub;
          T[u].p = v;
          pull(v);
     }
     void Cut(int u, int v) {
          reroot(u), access(v);
          T[v].ch[0] = T[u].p = 0;
          pull(v);
     }
     // Rooted tree LCA. Returns 0 if u and v arent connected.
     int LCA(int u, int v) {
          if (u == v) return u;
          access(u);
          int ret = access(v);
          return T[u].p ? ret : 0;
     }
     // Query subtree of u where v is outside the subtree.
     ll Subtree(int u, int v) {
          reroot(v), access(u);
          return T[u].vir + T[u].self;
     }
     // Query path [u..v]
     ll Path(int u, int v) {
          reroot(u), access(v);
          return T[v].path;
     }
     // Update vertex u with value v
     void Update(int u, ll v) {
          access(u);
          T[u].self = v;
          pull(u);
     }
};

void dk(){
     ll n,m;
     cin>>n>>m;
     LinkCut LCT(n);
     rep(i,0,n){
          
     }
      

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