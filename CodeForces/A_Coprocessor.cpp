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
     ll n,m;
     cin>>n>>m;
     vl v(n);    
     vector<vl>adj(n),adj2(n);
     vl in(n,0);
     vector<ll>dp(n,0);
     rep(i,0,n){
          cin>>v[i];
          dp[i]=v[i];
     }
     rep(i,0,m){
           ll x,y;
           cin>>x>>y;
           adj[x].pb(y);
           adj2[y].pb(x);
           in[y]++;

     }
     ll ans=0;
     queue<int>q;
     vl t;
     rep(i,0,n){
          if(in[i]==0){
               q.push(i);
               t.pb(i);
          }
     }
     while(!q.empty()){
          auto node=q.front();
          q.pop();
          ll val=dp[node];
          for(auto i:adj[node]){
               in[i]--;
               if(in[i]==0){
                    q.push(i);
                    t.pb(i);
               }
          }
     }
     for(auto i:t){
          for(auto j:adj2[i]){
               dp[i]=max(dp[i],dp[j]+(v[j]==0 and v[i]==1));
          }
          ans=max(ans,dp[i]);
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