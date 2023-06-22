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
vl v;
vector<vl>dp(510,vl(510,-1));

ll recur(ll i, ll j){
     if(i>j) return 0;
     if(i==j) return 1;
     if(dp[i][j]!=-1) return dp[i][j];

     ll ans=recur(i+1,j)+1;
     if(v[i]==v[i+1]) ans=min(ans,recur(i+2,j)+1);
     
     for(ll k=i+2;k<=j;k++){
          if(v[i]==v[k]){
               ans=min(ans,recur(i+1,k-1)+recur(k+1,j));
          }
     }

     return dp[i][j]=ans;
}


void dk(){
     cin>>n;
     v.resize(n);
     inp(v); 
     cout<<recur(0,n-1)<<endl;;
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