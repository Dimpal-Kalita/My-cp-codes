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





int n;
vector<array<ll,3>>v;
ll total=0;
vector<vector<ll>>dp;
ll recur(ll ind, ll sum){
     if(ind==n){
          if(sum>total-sum) return 0;
          else return 1e12;
     }
     if(dp[ind][sum]!=-1) return dp[ind][sum];
     ll x=(v[ind][0]+v[ind][1]+1)/2;
     ll val=max(0ll,x-v[ind][0]);
     return dp[ind][sum]=min(recur(ind+1,sum+v[ind][2])+val,recur(ind+1,sum));
}



void dk(){
     cin>>n;
     rep(i,0,n){
          int x,y,z;
          cin>>x>>y>>z;
          v.pb({x,y,z});
          total+=z;
     }
     dp.resize(n+1,vector<ll>(total+1,-1));
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