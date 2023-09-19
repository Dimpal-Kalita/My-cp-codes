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





/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(stack<T> v){cerr<< "[" ; while(!v.empty()){_print(v.top()); cerr<< " " ; v.pop();} cerr<< "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for(auto i: v){_print(i);cerr << " " ;} cerr<< "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------------Debug Ends--------------------------------------------------------------------*/





ll n;
vector<pll> v;
vector<vi>adj;
map<ll,vector<array<ll,3>>>mp;

struct LCA{
    vector<vector<int>> up;
    vector<int> tin, tout, distance;
    int timer;
    LCA(int n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(21, -1));
        distance.assign(n, 0);
    }
    void dfs(int v, int p, vector<vector<int>> &adj, int dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+1);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = 20; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        int w = lca(u, v);
        return abs(distance[u] + distance[v] - 2*distance[w]);
    }
};


template<class T> struct BIT {
     vector<T> s;
     int n;
     BIT(int n): s(n + 1), n(n) {}
     void update(int i, T v) {
          for (i++; i <= n; i += i & -i) s[i] += v;
     }
     T query(int i) { // EXCLUSIVE interval [0, i)
          T ans = 0;
          for (; i; i -= i & -i) ans += s[i];
          return ans;
     } // INCLUSIVE-EXCLUSIVE interval [l, r)
     T query(int l, int r) { return query(r) - query(l); }
     int kth(T k) { // 0-indexed, returns n if k > sum of tree
          if (k < 0) return -1;
          int i = 0;
          for (int pw = 1 << __lg(n); pw; pw >>= 1)
               if (i + pw <= n && s[i + pw] <= k) k -= s[i += pw];
          return i;
     }
};

void dk(){
     cin>>n;
     vector<ll>store(n+1);
     adj.resize(n+1);
     rep(i,0,n){
          ll x;
          cin>>x;
          v.pb({x,i});
          store[i]=x;
     }
     rep(i,0,n-1){
          ll a,b;
          cin>>a>>b;
          adj[a].pb(b);
          adj[b].pb(a);
     }
     LCA lca(n+1);
     lca.dfs(0,0,adj,0);
     BIT<ll> bit(2*n+10);
     
     int Q;
     cin>>Q;
     vector<ll>ans(Q+1);

     for(int i=0;i<Q;i++){
          ll x,y,val;
          cin>>x>>y>>val;
          mp[val].pb({x,y,i});
     }

     sort(all(v));

     int ind=0;
     for(auto [val, arr]:mp){
          while(ind<n && v[ind].F<=val-1){
               bit.update(lca.tin[v[ind].S],1);
               bit.update(lca.tout[v[ind].S],-1);
               ind++;
          }
          for(auto [x,y,ind1]:arr){
               ans[ind1]=bit.query(lca.tin[x])+bit.query(lca.tin[y])-2*bit.query(lca.tin[lca.lca(x,y)])+(store[lca.lca(x,y)]<=val-1);
               ans[ind1]=-ans[ind1];
          }
          while(ind<n and v[ind].F==val){
               bit.update(lca.tin[v[ind].S],1);
               bit.update(lca.tout[v[ind].S],-1);
               ind++;
          }
          for(auto [x,y,ind1]:arr){
               ans[ind1]+=bit.query(lca.tin[x])+bit.query(lca.tin[y])-2*bit.query(lca.tin[lca.lca(x,y)])+(store[lca.lca(x,y)]<=val);
          }
     }
     for(int i=0;i<Q;i++){
          cout<<ans[i]<<endl;
     }

}



int main()
{ 
    fast_io;
  
    int _=1;
//     cin>>_;''
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}