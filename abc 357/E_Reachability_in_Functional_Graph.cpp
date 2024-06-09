#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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

ll n;
vector<vl>adj;

vl vis,cycle;
vl dp;
vl in;
vl col;
ll find_cycle(ll u){
     if(col[u]==2 or adj[u].size()==0) return 0;
     if(col[u]==1) return u;
     col[u]=1;
     ll ret=find_cycle(adj[u][0]);
     col[u]=2;
     return ret;
}
 
ll get_cycle_size(ll u,ll sz){
     if(vis[u]==1) return sz;
     vis[u]++;
     return get_cycle_size(adj[u][0],sz+1);
}
void got_cycle(ll u,ll sz){
     if(vis[u]==2) return;
     vis[u]++;
     cycle[u]=1;
     dp[u]=sz;
     for(auto i:adj[u]){
          got_cycle(i,sz);
     }

}


ll calc(ll u){
     if(dp[u]!=0) return dp[u];
     dp[u]=1+calc(adj[u][0]);
     return dp[u];
}
void dk(){
      cin>>n;
      adj.assign(n+1,vl());
      vis.assign(n+1,0);
      cycle.assign(n+1,0);
      dp.assign(n+1,0);
      in.assign(n+1,0);
      col.resize(n+1,0);
      rep(i,1,n+1){
          ll x;
          cin>>x;
          if(i==x){
               cycle[i]=1;
               dp[i]=1;
          }
          else adj[i].pb(x);
      }
     //  cout<<find_cycle(1)<<endl;;
      
      rep(i,1,n+1){
          if(!cycle[i] and !vis[i]){
               ll node=find_cycle(i);
               // cout<<node<<endl;
               if(node!=0){
                    ll length=get_cycle_size(node,0);
                    got_cycle(node,length);
               }
          }
      }
      ll ans=0;
      rep(i,1,n+1){
          if(dp[i]==0){
               dp[i]=calc(i);
          }
          // cout<<dp[i]<<" ";
          ans+=dp[i];
      }
      cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   