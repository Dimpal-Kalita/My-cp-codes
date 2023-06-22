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

ll n;
vector<pll>v;
vector<vl>dp;

ll recur(ll ind , ll state){
     if(ind==n) return 0;

     if(dp[ind][state]!=-1) return dp[ind][state];

     ll ans=0;
     if(v[ind].F==0){
          ans=max(ans,recur(ind+1,state));
          ans=max(ans,recur(ind+1,0)+v[ind].S);
     }else{
          ans=max(ans,recur(ind+1,state));
          if(state==0){
               ans=max(ans,recur(ind+1,1)+v[ind].S);
          }
     }

     return dp[ind][state]=ans;
}



void dk(){
     cin>>n;
     v.resize(n);
     dp.resize(n+1,vl(3,-1));
     rep(i,0,n){
          ll x,y;
          cin>>x>>y;
          v[i]={x,y};
     }
     cout<<recur(0,0)<<endl;
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