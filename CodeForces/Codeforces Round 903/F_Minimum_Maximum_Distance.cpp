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





ll n;
vector<vl>adj;
vl mark;
vl dp,mx;

ll dfs(ll u,ll p){
     ll ans=0;
     for(auto v:adj[u]){
          if(v==p) continue;
          ans=max(ans,dfs(v,u));
     }
     if(ans) ans++;
     if(ans==0 and mark[u]) ans=1;
     return dp[u]=ans;
}

ll dfs2(ll u, ll p,ll carry){
     ll m=carry;
     map<ll,ll>mp;
     vl vp;
     vp.pb(m);
     for(auto v:adj[u]){
          if(v==p) continue;
          m=max(m,dp[v]);
          mp[dp[v]]++;
          vp.pb(dp[v]);
     }
     sort(all(vp));
     ll secondmx=0;
     if(vp.size()>1) secondmx=vp[vp.size()-2];
     ll ans=1;
     ll go=0;
     if(mark[u]) go=1;
     for(auto v:adj[u]){
          if(v==p) continue;
          ll x=dp[v];
          if(x==m and mp[x]==1){
               ans=max(ans,dfs2(v,u,secondmx==0?go:secondmx+1));
          }
          else{
               ans=max(ans,dfs2(v,u,m==0?go:m+1));
          }
     }
     return mx[u]=m;
}

void dk(){
     cin>>n;
     ll m;
     cin>>m;
     mark.assign(n+1,0);
     rep(i,0,m){
          ll x;
          cin>>x;
          mark[x]=1;
     }
     adj.assign(n+1,{});
     dp.assign(n+1,0);
     mx.assign(n+1,0);
     rep(i,0,n-1){
          ll x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
     }
     dfs(1,0);
     debug(dp);
     dfs2(1,0,0);
     debug(mx); 
     ll ans=1e9;
     mx[0]=1e9;
     for(auto i:mx) ans=min(ans,i);
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