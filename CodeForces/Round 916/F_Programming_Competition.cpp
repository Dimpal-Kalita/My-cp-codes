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
     vl v(n);
     vector<vl>adj(n+1);
     rep(i,2,n+1){
          ll x;
          cin>>x;
          adj[i].pb(x);
          adj[x].pb(i);
     }
     vector<vector<ll>>level(n+1);
     vl par(n+1);
     function<void(ll,ll,ll)>dfs=[&](ll node,ll parent, ll l){
          level[l].pb(node);
          par[node]=parent;
          for(auto child:adj[node]){
               if(child!=parent) dfs(child,node,l+1);
          }
     };
     dfs(1,1,1);
     ll ans=0,last=0;
     vl count(n+1);
     for(int i=n;i>0;i--){
          if(level[i].size()==0) continue;
          priority_queue<pll>pq;
          for(auto j:level[i]){
               pq.push({count[j]+1,j});
          }
          while(pq.size()>1){
               auto x=pq.top();
               pq.pop();
               auto y=pq.top();
               pq.pop();
               x.F--;
               y.F--;
               ans++;
               if(x.F) pq.push(x);
               if(y.F) pq.push(y);
          }
          if(pq.empty()) continue;
          auto x=pq.top();
          pq.pop();
          count[par[x.S]]+=x.F;
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