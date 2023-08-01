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


const int mx=5e4+10;
int n,m;
bitset<mx> bit[mx];
vector<vector<int>>adj(mx);
vector<int>vis(mx);

void dfs(int node){
     vis[node]=1;
     for(auto x:adj[node]){
         if(!vis[x]){
             dfs(x);
         }
         bit[node]|=bit[x];
     }
}

void dk(){
     cin>>n>>m;
     for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         adj[u].pb(v);
         bit[u][v]=1;
     }
     for(int i=1;i<=n;i++){
          if(!vis[i]){
              dfs(i);
          }
     }
     for(int i=1;i<=n;i++){
         cout<<bit[i].count()+1<<" ";
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