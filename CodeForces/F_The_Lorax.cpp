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






struct Tree {
     typedef ll T;
     static constexpr T unit = 0;
     T f(T a, T b) { return a+b; }
     vector<T> s;
     int n;
     Tree(int n = 0, T def = unit): s(2 * n, def), n(n) {}
     void update(int pos, T val) {
          for (s[pos += n] += val; pos /= 2;)
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


vector<vector<int>>adj;
vector<int>tin,tout;
int timer;

void dfs(int node, int par=0){
     tin[node]=++timer;
     for(auto child:adj[node]){
          if(child==par) continue;
          dfs(child,node);
     }

     tout[node]=++timer;
}


void dk(){
     int n,q;
     cin>>n>>q;
     adj.assign(n+1,{});
     tin.assign(n+1,0);
     tout.assign(n+1,0);
     timer=0;
     rep(i,0,n-1){
          int x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
     }
     dfs(1);
     debug(tin);
     debug(tout);
     Tree tree(2*n+1);
     while(q--){
          int a,b,x;
          cin>>a>>b>>x;
          if(x==0){
               int l=tin[a],r=tin[b];
               if(l>r) swap(a,b); 
               ll ans1=abs(tree.query(tin[b],tout[b]+1));
               cout<<ans1<<endl;
          }else{
               tree.update(tin[a],x);

               tree.update(tin[b],-x);
          }
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