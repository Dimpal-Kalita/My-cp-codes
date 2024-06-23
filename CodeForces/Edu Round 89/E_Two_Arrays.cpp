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


void dk(){
     ll n,m;
     cin>>n>>m; 
     vl a(n);
     inp(a);
     vl b(m);
     inp(b);
     vl mn(n+1,1e9);
     for(int i=n-1;i>=0;i--){
          mn[i]=min(mn[i+1],a[i]);
     }
     vl dp(m+1);

     if(mn[0]==b[0]) dp[0]=1;
     else dp[0]=0;

     ll j=0;

     while(mn[j]<=b[0] and j<n) j++;
     
     for(int i=1;i<m;i++){
          dp[i]=dp[i-1];
          ll last=j;
          while(mn[last]<b[i] and last<n) last++;
          while(mn[j]<=b[i] and j<n) j++;
          dp[i]=((j-last)*dp[i-1])%md;

     }
     cout<<dp[m-1]<<endl;
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