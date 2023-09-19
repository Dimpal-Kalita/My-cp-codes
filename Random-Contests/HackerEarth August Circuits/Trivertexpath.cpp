/**
 * 
 * author: Dimpal Kalita
 * date: 24/08/2023 12:23:26
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

void dfs(int node, int par,int le,vi &level,vector<vi>&adj){
    level[node]=le;
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,node,le+1,level,adj);
        }
    }
}

void dk(){
      int n;
      cin>>n;
      vector<vi>adj(n+1);
      rep(i,0,n-1){
           int x,y;
           cin>>x>>y;
           adj[x].pb(y);
           adj[y].pb(x);
      }
      LCA lca(n+1);
      lca.dfs(1,1,adj,0);
      vi level(n+1);
      dfs(1,1,0,level,adj);
      int q;
      cin>>q;
      while(q--){
          vi v(3);
          vector<pii>vp;
          for(auto &it:v){
            cin>>it;
            vp.pb({level[it],it});
          }
          sort(all(vp));
          int right=vp[2].S;
          int left=right;
          int l=v[0];
          for(auto i:v){
            l=lca.lca(i,l);
          }
          for(int i=1;i>=0;i--){
            if(lca.lca(vp[i].S,right)==l){
                left=vp[i].S;
                break;
            }
          }
          bool flag=1;
          for(auto i:v){
            if(!(level[l]<=level[i] && (lca.is_ancestor(i , left) || lca.is_ancestor(i , right)))){
                flag = false;
                break;
            }
        }
        cout<<(flag?"Yes":"No")<<endl;
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