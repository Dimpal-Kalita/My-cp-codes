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
     vl v(n+1);
     rep(i,1,n+1){
          cin>>v[i];
     }
     vector<vl>adj(n+1);
     rep(i,0,n-1){
          ll a,b;
          cin>>a>>b;
          adj[a].pb(b);
          adj[b].pb(a);
     }
     vl subtree(n+1),dp(n+1),par(n+1),taken(n+1);
     function<void(ll,ll)>dfs=[&](ll u,ll p){
          par[u]=p;
          subtree[u]=1;
          ll ans=0;
          for(auto x:adj[u]){
               if(x==p)continue;
               dfs(x,u);
               subtree[u]+=subtree[x];
               ll val=dp[x]+(v[x]^v[u])*subtree[x];
               taken[x]=val;
               ans+=val;
          }
          dp[u]+=ans;
     };
     dfs(1,1);
     vl req(n+1);
     function<void(ll,ll,ll,ll)>dfs2=[&](ll u,ll p,ll d,ll cnt){
          ll x=par[u];
          ll ans=(v[u]^v[x])*cnt;
          req[u]=ans+dp[u]+d;
          for(auto v:adj[u]){
               if(v==p) continue; 
               dfs2(v,u,req[u]-taken[v],cnt+subtree[u]-subtree[v]);
          }
     };
     dfs2(1,1,0,0);
     rep(i,1,n+1){
          cout<<req[i]<<" ";
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