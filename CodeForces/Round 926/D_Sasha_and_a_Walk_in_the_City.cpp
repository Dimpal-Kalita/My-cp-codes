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
     vector<vl>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     } 
     vl subtree(n+1,0);
     function<ll(ll,ll)>dfs=[&](ll u,ll p){
          ll sum=1;
          for(auto v:adj[u]){
               if(v==p) continue;
               sum+=dfs(v,u);
          }
          return subtree[u]=sum;
     };
     dfs(1,0);
     ll total=0;
     function<void(ll,ll)>dfs2=[&](ll u,ll p){
          vl v;
          ll ans=0,sum=0,ssum=0;
          for(auto x:adj[u]){
               if(x!=p){
                    v.pb(subtree[x]-1);
                    ans+=subtree[x];
                    sum+=(subtree[x]-1);
                    ssum+=subtree[x];
               }
          }
          for(auto x:v){
               sum-=x;
               ssum-=(x+1);
               ans+=(sum)*x;
               ans+=(ssum)*(x+1);
               // cout<<x<<" ";
          }
          cout<<u<<" "<<ans<<endl;
          for(auto x:adj[u]){
               if(x!=p){
                    dfs2(x,u);
               }
          }
          total+=ans;
     };
     dfs2(1,0);
     cout<<total+n+1<<endl;
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