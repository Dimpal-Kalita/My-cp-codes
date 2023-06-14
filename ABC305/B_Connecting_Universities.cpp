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


const int N=2e5+5;
ll n,m,ans=0;
vector<ll> adj[N],subTree(N),v;


void dfs(int node,int par){

     if(binary_search(all(v),node)) subTree[node]=1;

     for(auto &it:adj[node]){
          if(it==par) continue;
          dfs(it,node);
          subTree[node]+=subTree[it];
     }

     int mn=min(subTree[node],2*m-subTree[node]);
     ans+=mn;
}



void dk(){
     cin>>n>>m;
     v.resize(2*m);
     inp(v);
     sort(all(v));
     for(int i=0;i<n-1;i++){
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     dfs(1,0);
     cout<<ans<<endl;
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