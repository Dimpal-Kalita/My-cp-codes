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





ll n;
vector<set<ll>>adj;

bool cycle(ll node, vector<bool>&vis, vector<bool>&rec){
     vis[node]=true;
     rec[node]=true;
     for(auto x: adj[node]){
          if(!vis[x] && cycle(x,vis,rec)) return true;
          else if(rec[x]) return true;
     }
     rec[node]=false;
     return false;
}

bool detect_cycle(){
     vector<bool>vis(n+1,0),rec(n+1,0);
     rep(i,1,n+1){
          if(!vis[i]){
               if(cycle(i,vis,rec)) return 1;
          }
     }
     return 0;
}

vector<ll>dp;

ll dfs(ll node,vl &vis){
     if(vis[node]==1) return dp[node];
     ll ans=1;
     for(auto it:adj[node]){
          if(it>node){
               ans=max(ans,dfs(it,vis)+1);
          }else{
               ans=max(ans,dfs(it,vis));
          }
     }
     vis[node]=1;
     return dp[node]=ans;
}

void dk(){
     cin>>n;
     adj.assign(n+1,set<ll>());
     dp.resize(n+1,0);
     vl vis(n+1,0);
     rep(i,1,n+1){
          ll sz;
          cin>>sz;
          rep(j,0,sz){
               ll x;
               cin>>x;
               adj[i].insert(x);
          }
     }
     if(detect_cycle()){
          cout<<-1<<endl;
          return;
     }
     rep(i,1,n+1){
          if(!vis[i]) dfs(i,vis);
     }
     // debug(dp);
     ll ans=*max_element(all(dp));
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