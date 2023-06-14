// Problem: Path Value
// URL: https://www.hackerearth.com/challenges/competitive/april-circuits-23/algorithm/path-value-2-54ac4ca3/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author: Dimpal Kalita
// 22-04-2023 08:31:02
 
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
 
 
 
 
const int N=2e5;
ll n, m,s,e;
vector<ll>adj[N];
 
 
struct DSU {
    vector<int> s;
    DSU(int n): s(n, -1) {}
    int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b], s[b] = a;
        return true;
    }
    int size(int i) { return -s[find(i)]; }
    bool same(int a, int b) { return find(a) == find(b); }
};
 
 
 
void dk(){ 
    cin>>n>>m;
    cin>>s>>e;
    vector<pll> temp;
    rep(i,0,m){
        ll x, y;
        cin>>x>>y;
        temp.pb({x,y});
    }
    
    vector<ll> v(n+1);
    
    rep(i,1,n+1){
        cin>>v[i];
    }
    
    vector<pair<ll,pll>>vp;
    
    for(auto it:temp){
        vp.pb({abs(v[it.F]-v[it.S]),{it.F,it.S}});
    }
    
    sort(all(vp));
    
    ll ans=0;
    DSU dsu(n+1);
    
    for(auto it:vp){
        if(dsu.same(it.S.S,it.S.F)) continue;
        if(dsu.same(s,e)) break;
        dsu.join(it.S.S,it.S.F);
        ans= max(ans, it.F);
    }
    
    cout<<ans<<endl;
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
Language: C++14