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





struct LCA{
    vector<vector<int>> up,mn;
    vector<int> tin, tout, distance;
    int timer;
    LCA(int n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(21, -1));
        mn.assign(n, vector<int>(21, INT_MAX));
        distance.assign(n, 0);
    }
    void dfs(int v, int p, vector<vector<pii>> &adj, int dis,int val=INT_MAX) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        mn[v][0]=val;
        for (int i = 1; i < 21; i++){
            up[v][i] = up[up[v][i - 1]][i - 1];
            mn[v][i]= min(mn[v][i-1],mn[up[v][i-1]][i-1]);
        }
        for (auto [u,w]: adj[v]) {
            if (u == p) continue;
            dfs(u, v, adj, dis+1,w);
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
 

void dk(){
     int n,m;
     cin>>n>>m;
     vector<vector<pair<int,int>>>adj(n+1);
     for(int i=0;i<m;i++){
          int x,y,w;
          cin>>x>>y>>w;
          adj[x].pb({y,w});
          adj[y].pb({x,w});
     }
     LCA lca(n+1);
     lca.dfs(1,1,adj,0);
     int q;
     cin>>q;
     while(q--){
          int x,y;
          cin>>x>>y;
          int ans=INT_MAX;
          int l=lca.lca(x,y), a=lca.dist(x,l), b=lca.dist(y,l);
          for(int i=20;i>=0;i--){
               if(a&(1<<i)){
                    ans=min(ans,lca.mn[x][i]);
                    x=lca.up[x][i];
                    a-=(1<<i);
               }
          }
          for(int i=20;i>=0;i--){
               if(b&(1<<i)){
                    ans=min(ans,lca.mn[y][i]);
                    y=lca.up[y][i];
                    b-=(1<<i);
               }
          }
          cout<<ans<<endl;
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