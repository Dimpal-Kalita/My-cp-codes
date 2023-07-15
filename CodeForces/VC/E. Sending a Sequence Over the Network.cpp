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


void dk(){
     int n;
     cin>>n;
     vi v(n+1);
     rep(i,1,n+1) cin>>v[i];
     vector<bool>dp(n+1,0);

     dp[0]=1;
     for(int i=1;i<=n;i++){
         if(i-v[i]-1>=0 and dp[i-v[i]-1]){
             dp[i]=1;
         }
         if(i+v[i]<=n and dp[i-1]){
             dp[i+v[i]]=1;
         }
     }

     cout<<(dp[n]?"YES":"NO")<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}
