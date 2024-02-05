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

template<class T> struct BIT {
     vector<T> s;
     int n;
     BIT(int n): s(n + 1), n(n) {}
     void update(int i, T v) {
          ll x=v;
          for (i++; i <= n; i += i & -i) s[i] = max(s[i], x);
     }
     T query(int i) { // EXCLUSIVE interval [0, i)
          T ans = 0;
          for (; i; i -= i & -i) ans = max(ans,s[i]);
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

ll solve(vl v){
     ll n=v.size();
     vl a,b;
     b.pb(v[0]);
     for(int i=1;i<n;i++){
          if(v[i]>b.back()){
               a.pb(v[i]);
          }else{
               b.pb(v[i]);
          }
     }
     debug(a);
     debug(b);
     ll ans=0;
     for(int i=0;i<sz(a)-1;i++){
          if(a[i]<a[i+1]){
               ans++;
          }
     }
     for(int i=0;i<sz(b)-1;i++){
          if(b[i]<b[i+1]){
               ans++;
          }
     }
     return ans;
}


ll solve2(vl v){
     ll n=v.size();
     vl a,b;
     reverse(all(v));
     b.pb(v[0]);
     for(int i=1;i<n;i++){
          if(v[i]<b.back()){
               a.pb(v[i]);
          }else{
               b.pb(v[i]);
          }
     }
     reverse(all(a));
     reverse(all(b));
     // debug(a);
     // debug(b);
     ll ans=0;
     for(int i=0;i<sz(a)-1;i++){
          if(a[i]<a[i+1]){
               ans++;
          }
     }
     for(int i=0;i<sz(b)-1;i++){
          if(b[i]<b[i+1]){
               ans++;
          }
     }   
     return ans;
}


void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     ll ans=0;
     priority_queue<ll,vector<ll>,greater<ll>> pq;
     for(auto i:v){
          ll x=1e10,y=1e10;
          if(pq.size()>1){
               x=pq.top();
               pq.pop();
          }
          if(pq.size()>1){
               y=pq.top();
               pq.pop();
          }
          if(i>x and i>y){
               ans++;
          }
          pq.push(y);
          pq.push(x);
          pq.push(i);
     }
     cout<<ans<<endl;
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