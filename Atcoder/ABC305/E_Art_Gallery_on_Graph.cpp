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





ll n,m,k;
map<ll,ll> guard;
vector<vector<ll>>adj(2e5+7);
set<ll> st;
vector<ll> vis(2e5+7),dp(2e5+7);




void dk(){
     cin>>n>>m>>k;
     rep(i,0,m){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     rep(i,0,k){
          ll u,v;
          cin>>u>>v;
          guard[u]=v+1;
     }
     
     priority_queue<pll,vector<pll>,less<pll>> pq;
     for(auto it:guard){
          pq.push({it.S,it.F});
          dp[it.F]=it.S;
     }
     while(!pq.empty()){
          ll u=pq.top().S;
          ll d=pq.top().F;
          pq.pop();
          if(vis[u]) continue;
          for(auto v: adj[u]){
             if(dp[v]<d-1 and d-1>0){
                  dp[v]=d-1;
                  pq.push({d-1,v});
             }
          }
          vis[u]=1;
     }
     rep(i,1,n+1){
          if(dp[i]) st.insert(i);
     }
     
     cout<<st.size()<<endl;
     for(auto x: st) cout<<x<<" ";
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