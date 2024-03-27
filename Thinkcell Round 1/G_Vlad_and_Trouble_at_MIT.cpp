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


#define arr array<ll,4>
void dk(){
     ll n;
     cin>>n;
     vector<vl>adj(n+1);
     rep(i,2,n+1){
          ll x;
          cin>>x;
          adj[x].pb(i);
          adj[i].pb(x);
     }
     string s;
     cin>>s;
     vector<ll>dp(n+1,1e9);
     function<arr(ll,ll)> dfs=[&](ll u,ll p){
          ll sleep1=0,party1=0;
          ll sleep=0,party=0;
          ll ans=0;
          for(auto v:adj[u]){
               if(v==p) continue;
               auto [sc,py,sc1,py1]=dfs(v,u);
               ans+=dp[v];
               sleep+=(sc>0);
               party+=(py>0);
               sleep1+=(sc1>0);
               party1+=(py1>0);
          }
          if(s[u-1]=='S'){
               ans+=min(party,party1);
               party=0;
               party1=0;
               dp[u]=ans;
          }
          else if(s[u-1]=='P'){
               ans+=min(sleep,sleep1);
               sleep=0;
               sleep1=0;
               dp[u]=ans;
          }else{
          
          }
          sleep+=(s[u-1]=='S');
          party+=(s[u-1]=='P');
          sleep1+=(s[u-1]=='S');
          party1+=(s[u-1]=='P');

          return arr{sleep,party,sleep1,party1};
     };
     dfs(1,0);
     cout<<dp[1]<<endl;
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