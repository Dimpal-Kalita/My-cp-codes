/**
 * 
 * author: Dimpal Kalita
 * date: 18/05/2023 21:04:12
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


vector<vl> adj;
vl v, dp;

void dfs(ll u, ll p=0){
     ll mn=1e18,sum=0;
     for(auto it:adj[u]){
         if(it==p) continue;
         dfs(it,u);
         sum+=dp[it];
         mn=min(mn,dp[it]);
     }
     if(dp[u]!=0) return;
     if(v[u]==1) dp[u]=mn;
     else dp[u]=sum;
}

void dk(){
      ll n;
      cin>>n;
      adj.resize(n+1);
      v.resize(n+1);
      dp.resize(n+1);
      rep(i,1,n+1) cin>>v[i];
      for(int i=2;i<=n;i++){
          ll x;
          cin>>x;
          adj[x].pb(i);
          // adj[i].pb(x);
      }
      ll leaf=0;
      for(int i=2;i<=n;i++){
          if(adj[i].size()==1){
               leaf++;
               dp[i]=1;
          }
      }
      dfs(1);
      ll ans=0;
      cout<<leaf<<endl;
      cout<<leaf-dp[1]+1<<endl;

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