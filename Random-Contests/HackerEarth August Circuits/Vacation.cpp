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
    void dfs(int v, int p, vector<vector<int>> &adj,vector<int>&val, int dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        mn[v][0]=val[v];
        for (int i = 1; i < 21; i++){
            up[v][i] = up[up[v][i - 1]][i - 1];
            mn[v][i]=min(mn[v][i-1],mn[up[v][i-1]][i-1]);
        }
        for (auto u: adj[v]) {
            if (u == p) continue;
            dfs(u, v, adj,val, dis+1);
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
      ll n;
      cin>>n;
      vi val(n);
      inp(val);
      vector<vector<int>> adj(n);
      for(int i=0;i<n-1;i++){
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
      }
      LCA lca(n);
      lca.dfs(0,0,adj,val,0);
      
      int q;
      cin>>q;
      while(q--){
            int u,v,k;
            cin>>u>>v>>k;
            if(lca.is_ancestor(u,v)){
                int dist=lca.dist(u,v);
                int l=0,r=dist;
                int temp=0;
                while(l<r){
                    int mid=(l+r)/2;
                    int mn=1e9;
                    for(int i=20;i>=0;i--){
                        if(mid&(1<<i)){
                            mn=min(mn,lca.mn[v][i]);
                        }
                    }
                    if(mn>=k){
                        temp=mid;
                        l=mid+1;
                    }else{
                        r=mid;
                    }
                }
                cout<<temp<<endl;
            }else if(lca.is_ancestor(v,u)){
                int dist=lca.dist(u,v);
                int l=0,r=dist;
                int temp=0;
                while(l<r){
                    int mid=(l+r)/2;
                    int mn=1e9;
                    for(int i=20;i>=0;i--){
                        if(mid&(1<<i)){
                            mn=min(mn,lca.mn[u][i]);
                        }
                    }
                    if(mn>=k){
                        temp=mid;
                        l=mid+1;
                    }else{
                        r=mid;
                    }
                }
                cout<<temp<<endl;
            }else{
                int w=lca.lca(u,v);
                int l=0,r=lca.dist(u,w);
                int temp=0;
                while(l<r){
                    int mid=(l+r)/2;
                    int mn=1e9;
                    for(int i=20;i>=0;i--){
                        if(mid&(1<<i)){
                            mn=min(mn,lca.mn[u][i]);
                        }
                    }
                    if(mn>=k){
                        temp=mid;
                        l=mid+1;
                    }else{
                        r=mid;
                    }
                }
                
                int ans=temp;
                temp=0;
                l=0,r=lca.dist(v,w);
                while(l<r){
                    int mid=(l+r)/2;
                    int mn=1e9;
                    for(int i=20;i>=0;i--){
                        if(mid&(1<<i)){
                            mn=min(mn,lca.mn[v][i]);
                        }
                    }
                    if(mn>=k){
                        temp=mid;
                        l=mid+1;
                    }else{
                        r=mid;
                    }
                }
                ans+=temp;
                cout<<min(ans,lca.dist(u,v))<<endl;
            }
        }
}



int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}