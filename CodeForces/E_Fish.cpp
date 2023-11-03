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
      ll n;
      cin>>n;
      vector<vector<lld>> v(n,vector<lld>(n));
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              cin>>v[i][j];
          }
      }

      vector<lld> dp(1<<n,-1);
      auto recur=[&](auto recur,ll val)->lld{
          if(val==0) return 1;
          if(dp[val]!=-1) return dp[val];
          lld ans=0;
          for(int i=0;i<n;i++){
               if((val&(1<<i))) continue;
               for(int j=0;j<n;j++){
                    if(i==j || !(val&(1<<j))) continue;
                    ans=(ans+v[i][j]*recur(recur,val^(1<<j)));
               }
          }
          ll x=__builtin_popcount(val);
          ans/=x*(x+1)/2;
          return dp[val]=ans;
      };

      ll mx=(1<<n)-1; 
      cout<<fixed<<setprecision(10);
      for(int i=0;i<n;i++){
          cout<<recur(recur,mx^(1<<i))<<" ";
      }
      cout<<endl;
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