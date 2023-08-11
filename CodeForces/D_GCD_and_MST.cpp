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
     ll n,p;
     cin>>n>>p;
     vl v(n),vis(n,0);
     inp(v);
     vector<pll>vp;
     rep(i,0,n){
          vp.pb({v[i],i});
     }
     sort(all(vp));
     DSU dsu(n+1);
     ll ans=0;
     for(int i=0;i<n;i++){
          if(vis[vp[i].S]) continue;
          if(vp[i].F>=p) break;
          int ind=vp[i].S;
          for(int j=ind+1;j<n;j++){
               if(v[j]%v[ind]==0){
                    if(dsu.join(ind,j)){
                         ans+=v[ind];
                         vis[j]=1;
                    }
               }else{
                    break;
               }
          }
          for(int j=ind-1;j>=0;j--){
               if(v[j]%v[ind]==0){
                    if(dsu.join(ind,j)){
                         ans+=v[ind];
                         vis[j]=1;
                    }
               }else{
                    break;
               }
          }
     }
     
     for(int i=0;i<n-1;i++){
          if(dsu.join(i,i+1)){
               ans+=p;
          }
     }
     cout<<ans<<endl;
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