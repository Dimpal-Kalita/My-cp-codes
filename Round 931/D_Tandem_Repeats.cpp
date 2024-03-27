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
     string s;
     cin>>s;
     ll n=s.length();
     ll ans=0;
     vector<vl>dp(n+1,vl(n+1,0));
     for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
               dp[j-i][i+1]=dp[j-i][i];
               if(s[j]=='?' or s[i]=='?') continue;
               if(s[i]!=s[j]) dp[j-i][i+1]+=1;
          }
     }

     for(ll i=0;i<=n;i++){
          for(ll j=i;(2*j-i-1)<n;j++){
               ll x=dp[j-i][j]-dp[j-i][i];
               if(x==0) ans=max(ans,2*(j-i));
          }
     }
     cout<<ans<<endl;
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