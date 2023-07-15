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




void dk(){
     ll n1,n2,m;
     cin>>n1>>n2>>m;
     vector<vi>adj(n1+n2+2,vi());
     rep(i,0,m){
         int u,v;
         cin>>u>>v;
         adj[u].pb(v);
         adj[v].pb(u);
     }
     vector<bool>vis(n1+n2+2,false);
     vector<ll>dist(n1+n2+2,0);
     queue<int>q;
     q.push(1);
     vis[1]=true;
     ll ans=0;
     while(!q.empty()){
         int u=q.front();
         q.pop();
         for(auto v:adj[u]){
             if(!vis[v]){
                 vis[v]=true;
                 dist[v]=dist[u]+1;
                 q.push(v);
             }
         }
     }
     // debug(dist);
     rep(i,1,n1+n2+1){
          ans=max(ans,dist[i]);
     }
     vis.assign(n1+n2+2,false);
     dist.assign(n1+n2+2,0);
     q.push(n1+n2);
     vis[n1+n2]=true;
     while(!q.empty()){
         int u=q.front();
         q.pop();
         for(auto v:adj[u]){
             if(!vis[v]){
                 vis[v]=true;
                 dist[v]=dist[u]+1;
                 q.push(v);
             }
         }
     }
     // debug(dist)
     ll val=0;
     rep(i,1,n1+n2+1){
          val=max(val,dist[i]);
     }
     cout<<ans+val+1<<endl;
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