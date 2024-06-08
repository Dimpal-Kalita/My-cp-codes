#include<bits/stdc++.h>
using namespace std;

#define md                  998244353
#define pb                  push_back
#define endl                "\n"
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


const int N=5e3+10;
void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     sort(all(v));
     vl dp(N+1,0);
     ll ans=0;
     dp[0]=1;
     for(int i=0;i<n;i++){
          vl ndp=dp;
          ndp[0]=1;
          for(ll j=v[i];j<N;j++){
               ndp[j]=(ndp[j]+dp[j-v[i]])%md;
          }
          vl temp(N+1,0);
          for(ll j=v[i];j<N;j++){
               temp[j]=dp[j-v[i]];
          }
          for(ll j=v[i];j<N;j++){
               ans=(ans+max(v[i],(j+1)/2)*temp[j]%md)%md;
          }
          dp=ndp;
     }
     cout<<ans%md<<endl;
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