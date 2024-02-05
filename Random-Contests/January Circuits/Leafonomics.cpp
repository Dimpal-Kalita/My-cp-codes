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




void dk(){
     ll n;
     cin>>n;
     vector<vector<pll>> adj(n+1);      
     rep(i,0,n-1){
          ll u,v,w;
          cin>>u>>v>>w;
          adj[u].pb({v,w});
          adj[v].pb({u,w});
     }
     vl dp(n+1,0);
     function<ll(ll,ll)> dfs=[&](ll u,ll p)->ll{
          ll mn=1e10;
          vl v;
          for(auto x: adj[u]){
               if(x.F==p) continue;
               v.pb(dfs(x.F,u)+x.S);
          }
          sort(all(v));
          if(adj[u].size()==1 and u!=1) mn=0;
          if(v.size()>0) mn=min(mn,v[0]);
          return dp[u]=mn;
     };
     vl ans(n+1);
     function<void(ll,ll,ll)> dfs2=[&](ll u,ll p,ll val){
          vector<pll>vp;
          for(auto x: adj[u]){
               if(x.F==p) continue;
               vp.pb({dp[x.F]+x.S,x.F});
          }
          vp.pb({val,u});
          sort(all(vp));
          for(auto x:adj[u]){
               if(x.F==p) continue;
               if(vp[0].S==x.F){
                    dfs2(x.F,u,vp[1].F+x.S);
               }
               else{
                    dfs2(x.F,u,vp[0].F+x.S);
               }
          }
          ans[u]=min(vp[0].F,dp[u]);
     };
     dfs(1,0);
     debug(dp);
     dfs2(1,0,1e15);
     rep(i,1,n+1){
          cout<<ans[i]<<" ";
     }
     cout<<endl;
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