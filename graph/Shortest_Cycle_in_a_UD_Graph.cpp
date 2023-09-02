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


/// @brief Shortest Cycle in a Undirected Graph
// https://www.eolymp.com/en/contests/32919/problems/386100

void dk(){
      ll n,m;
      cin>>n>>m;
      vector<vl>adj(n+1);
      rep(i,0,m){
           ll x,y;
           cin>>x>>y;
           adj[x].pb(y);
           adj[y].pb(x);
      }

      ll ans=1e8;
      rep(i,0,n){
          vl dist(n+1,1e8),par(n+1,-1);
          dist[i]=0;
          queue<ll>q;
          q.push(i);
          while(!q.empty()){
               ll x=q.front();
               q.pop();
               for(auto j:adj[x]){
                    if(dist[j]==1e8){
                         dist[j]=dist[x]+1;
                         par[j]=x;
                         q.push(j);
                    }
                    else if(par[x]!=j){
                         ans=min(ans,dist[x]+dist[j]+1);
                    }
               }
          } 
      }
      if(ans==1e8) cout<<"impossible"<<endl;
      else cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    cout<<"Case "<<i+1<<": ";
    dk();
   }
  return 0;
}