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
     vector<vl>adj(n+1);
     for(int i=0;i<n-1;i++){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     vl count(n+1),dist1(n+1);
     function<void(ll,ll,ll)>dfs=[&](ll u,ll p,ll d){
          if(adj[u].size()==1 and u!=1) count[u]=1;
          dist1[u]=d;
          for(auto v:adj[u]){
               if(v!=p){
                    dfs(v,u,d+1);
                    count[u]+=count[v];
               }
          }
     };
     dfs(1,0,0);
     debug(count);
     debug(dist1);
     priority_queue<pll,vector<pll>,greater<pll>>pq;
     vector<ll>dist(n+1,1e10);
     for(int i=1;i<=n;i++){
          if(adj[i].size()==1 and i!=1){
               dist[i]=0;
               pq.push({0,i});
          }
     }
     while(!pq.empty()){
          auto [d,u]=pq.top();
          pq.pop();
          dist[u]=d;
          for(auto v:adj[u]){
               if(dist[v]>dist[u]+1){
                    dist[v]=dist[u]+1;
                    pq.push({dist[v],v});
               }
          }
     }
     debug(dist);
     ll ans=0;
     for(int i=1;i<=n;i++){
          if(dist1[i]>=dist[i] and adj[i].size()>1){
               ans=max(ans,count[i]);
          }
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