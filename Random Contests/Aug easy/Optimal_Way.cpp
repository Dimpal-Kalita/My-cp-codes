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
vl v;
vector<vl>dp;
ll recur(ll ind, ll val){
     if(ind>k) return 0;
     if(dp[ind][val]!=-1) return dp[ind][val];
     ll ans=0;
     for(int i=0;i<n;i++){
          if(val&(1<<i)) continue;
          for(int j=i+1;j<n;j++){
               if(val&(1<<j)) continue;
               ll temp=val|(1<<i);
               temp=temp|(1<<j);
               ans=max(ans,recur(ind+1,temp)+ind*(v[i]&v[j]));
          }
     }
     return dp[ind][val]=ans;
}


void dk(){
     cin>>n;
     v.assign(n,0);
     inp(v);
     cin>>k;
     dp.assign(k+1,vl(1<<n,-1));
     cout<<recur(1,0)<<endl;
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