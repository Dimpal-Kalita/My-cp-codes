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

ll n,k;
vector<vl>adj;
vl col,dp;
bool flag;
void cycle(ll node, ll cur){
     col[node]=1;
     dp[node]=cur;
     for(auto child:adj[node]){
          if(col[child]==0){
               cycle(child,cur+1);
          }else if(col[child]==1){
               ll size=cur-dp[child]+1;
               if(size!=k) flag=0;
          }
     }
     col[node]=2;
}


void dk(){
     cin>>n>>k;
     adj.assign(n+1,{});
     dp.assign(n+1,0);
     col.assign(n+1,0);
     flag=1;
     vl v;
     rep(i,0,n){
          int x;
          cin>>x;
          v.pb(x);
          adj[i+1].pb(x);
     }
     if(k==1){
          vl temp(n);
          iota(all(temp),1);
          if(v!=temp){
               flag=0;
          }
     }
     rep(i,1,n+1){
          if(!col[i]){
               cycle(i,0);
          }
     }
     cout<<(flag?"YES":"NO")<<endl;
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