/**
 * 
 * author: Dimpal Kalita
 * date: 26/05/2023 22:29:36
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
vector<vl> dp;

ll MCM(ll i,ll j){
     if(i==j) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     ll ans=INT_MIN;
     for(ll k=i;k<j;k++){
          ans=max(ans,MCM(i,k)+MCM(k+1,j)+v[i-1]*v[k]*v[j]);
     }
     return dp[i][j]=ans;
}


void dk(){
     cin>>n;
     v.resize(n+2); 
     dp.resize(n+2,vl(n+2,-1));     
     v[0]=1;
     rep(i,1,n+1) cin>>v[i];
     v[n+1]=1;
     cout<<MCM(1,n+1)<<endl;
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