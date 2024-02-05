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
     int n,x,z;
     cin>>n>>x>>z;
     vector<int>v(n);
     inp(v);
     ll dp[n+1][x+1];
     for(int i=0;i<=n;i++){
          for(int j=0;j<=x;j++){
               dp[i][j]=1e15;
          }
     }

     
     dp[0][0]=0;
     int req=(x-z%x)%x;
     for(int i=0;i<n;i++){
          for(int j=0;j<=x;j++){
               ll y=((j+v[i]%x))%x;
               dp[i+1][y]=min(dp[i+1][y],dp[i][j]+v[i]);
               dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
          }
     }
     ll ans=dp[n][req];
     if(ans>=1e15) cout<<-1<<endl;
     else cout<<(ans+z)/x<<endl;
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