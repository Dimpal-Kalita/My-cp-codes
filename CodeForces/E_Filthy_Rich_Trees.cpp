/**
 * 
 * author: Dimpal Kalita
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000000
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






struct Tree {
     typedef lld T;
     static constexpr T unit = 0.0;
     T f(T a, T b) { return a+b; } 
     vector<T> s;
     int n;
     Tree(int n = 0, T def = unit): s(2 * n, def), n(n) {}
     void update(int pos, T val) {
          for (s[pos += n] = val; pos /= 2;)
               s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
     }
     T query(int b, int e) { 
          T ra = unit, rb = unit;
          for (b += n, e += n; b < e; b /= 2, e /= 2) {
               if (b % 2) ra = f(ra, s[b++]);
               if (e % 2) rb = f(s[--e], rb);
          }
          return f(ra, rb);
     }
};


vector<ll>tin,tout;
vector<vector<ll>>adj;
ll timer=0;
void dfs(ll u,ll p=0){
     tin[u]=++timer;
     for(auto v:adj[u]){
          if(v==p) continue;
          dfs(v,u);
     }
     tout[u]=timer;
}

void dk(){
     int n;
     cin>>n;
     adj.resize(n+1);
     tin.resize(n+1);
     tout.resize(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     Tree tree(n+2);
     dfs(1);

     int q;
     cin>>q;
     while(q--){
          int t;
          cin>>t;
          if(t==1){
               lld x,y;
               cin>>x>>y;
               lld val=log2(y);
               tree.update(tin[x],val); 
          }
          else{
               ll x,y;
               cin>>x>>y;
               lld l=tree.query(tin[x],tout[x]+1);
               lld r=tree.query(tin[y],tout[y]+1);
               
               cout<<fixed<<setprecision(10);
               lld ans=pow2(2.0,l-r);
               if(ans>=1e9){
                    cout<<1e9<<endl;
               }else{
                    cout<<ans<<endl;
               }

          }
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