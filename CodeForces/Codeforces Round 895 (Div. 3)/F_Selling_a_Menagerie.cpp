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



void dk(){
     ll n;
     cin>>n;
     vl cost(n+1,0),indegree(n+1,0);
     vector<vl>adj(n+1);
     rep(i,0,n){
          ll x;
          cin>>x;
          adj[i+1].pb(x);
          indegree[x]++;
     }
     rep(i,0,n){
          cin>>cost[i+1];
     }
     vl sold(n+1);
     rep(i,1,n+1){
          if(sold[i] || indegree[i]) continue;
          queue<ll>q;
          q.push(i);
          while(!q.empty()){
               ll u=q.front();
               cout<<u<<" ";
               sold[u]=1;
               q.pop();
               for(auto v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0){
                         q.push(v);
                    }
               }
          }
     }

     vector<pll> notsold;
     for(int i=1;i<=n;i++){
          if(!sold[i]){
               notsold.pb({cost[i],i});
          }
     }
     sort(all(notsold));
     for(auto [xx,cow]:notsold){
          if(sold[cow]) continue;
          queue<ll>q;
          q.push(cow);
          while(!q.empty()){
               ll u=q.front();
               sold[u]=1;
               q.pop();
               for(auto v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0){
                         cout<<v<<" ";
                         q.push(v);
                    }
               }
          }
     }
     cout<<endl;
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