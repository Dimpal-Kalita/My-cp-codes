/**
 * 
 * author: Dimpal Kalita
 * date: 29/04/2023 13:53:45
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


const int N=2e5+7;

vl adj[N] , dist1(N,0),dist2(N,0);

void dfs(ll node,ll par, ll distance, vl &dist){
     dist[node]=max(dist[node],distance);

     for(auto child: adj[node]){
          if(child!=par){
               dfs(child,node,distance+1,dist);
          }
     }
}


void dk(){
     ll n;
     cin>>n;
     rep(i,0,n-1){
          ll x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
     }
     dfs(1,-1,0,dist1);
     ll mx=0,mxnode=0;
     rep(i,1,n+1){
          if(dist1[i]>mx){
               mx=dist1[i];
               mxnode=i;
          }
     }
     dfs(mxnode,-1,0,dist2);
     mx=0,mxnode=-1;
     rep(i,1,n+1){
          if(dist2[i]>mx){
               mx=dist2[i];
               mxnode=i;
          }
     }
     dfs(mxnode,-1,0,dist1);
     for(int i=1;i<=n;i++){
          cout<<max(dist1[i],dist2[i])<<" ";
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