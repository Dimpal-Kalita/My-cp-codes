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





const int N = 2e5+5;
vector<ll> adj[N],dist(N,0),height(N,0);

ll dfs(ll node,ll par){
     ll mx=0;
     for(auto child: adj[node]){
         if(child!=par){
            mx=max(mx,dfs(child,node));
         }
     }
     return height[node]=mx+1;
}

void helper(ll node,ll par){
     vector<ll> v;
     for(auto child: adj[node]){
         if(child!=par){
            v.pb(height[child]);
         }
     }
     v.pb(0);
     v.pb(0);
     sort(all(v));
     for(auto child:adj[node]){
          if(child==par) continue;
          if(height[child]==v.back()){
               dist[child]=max(dist[node]+1,v[v.size()-2]+2);
          }else{
               dist[child]=max(dist[node]+1,v.back()+2);
          }
          helper(child,node);
     }
     dist[node]=max(dist[node],height[node]);
}



void dk(){
     ll n;
     cin>>n;
     ll root=0;
     rep(i,0,n-1){
          ll x;
          cin>>x;       
          adj[i+2].pb(x);
          adj[x].pb(i+2);
          if(x==1){
               root=i+2;
          }
     }
     dfs(root,-1);
     helper(root,-1);
     ll mx=1e8;
     for(int i=1;i<=n;i++){
          mx=min(mx,dist[i]);
     }
     // cout<<mx<<endl;
     // debug(dist);
     for(int i=1;i<=n;i++){
          if(dist[i]==mx){
               cout<<i<<" ";
          }
     }
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