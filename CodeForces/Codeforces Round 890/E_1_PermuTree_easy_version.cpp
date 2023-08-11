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





bool recur(ll ind, ll sum,ll n,vector<ll>&v,vector<vector<ll>>&dp){
     if(sum==0) return 1;
     if(ind>=n || sum<0) return 0;
     if(dp[ind][sum]!=-1) return dp[ind][sum];
     bool ans= recur(ind+1,sum,n,v,dp) || recur(ind+1,sum-v[ind],n,v,dp);
     return dp[ind][sum]=ans;
}

ll calc(vector<ll>&v){
     if(v.size()==0) return 0;
     ll sum=accumulate(all(v),0ll);
     vector<vector<ll>>dp(sz(v),vector<ll>(sum+1,-1));
     for(int i=sum/2;i>=0;i--){
          if(recur(0,i,sz(v),v,dp)){
               return (i*(sum-i));
          }
     }
     return 0;
}
ll n;
vector<vector<ll>>adj;

ll ret;
ll dfs(ll node,ll par){
     ll ans=1;
     vector<ll>v;
     for(auto x:adj[node]){
          if(x!=par){
               ll p=dfs(x,node);
               ans+=p;
               v.pb(p);
          }
     }
     ret+=calc(v);
     return ans;
}

void dk(){
     cin>>n;
     adj.resize(n+1);
     ret=0;
     rep(i,1,n){
          ll x;
          cin>>x;
          adj[x].pb(i+1);
          adj[i+1].pb(x);
     }
     dfs(1,0);
     cout<<ret<<endl;
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