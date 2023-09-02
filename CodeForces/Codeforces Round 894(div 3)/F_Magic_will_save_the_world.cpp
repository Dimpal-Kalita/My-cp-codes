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


ll w,f,n;
vi v;


bool check(ll curw,ll curf,ll sum){
     if(curf>=1e6 || curw>=1e6) return 1;
     ll mx=max(curw,curf);
     vector<int>dp(mx+1,INT_MIN);

     dp[0]=0;
     for(int j=0;j<n;j++){
          for(int i=mx;i>=0;i--){
             if(v[j]<=i and dp[i-v[j]]!=INT_MIN){
                    dp[i]=max(dp[i],(dp[i-v[j]]+v[j]));
             }
          }
     }
     ll mxx=0;
     for(int i=0;i<=mx;i++){
          mxx=max(mxx,(ll)dp[i]);
     }
     sum-=mxx;
     return sum<=min(curw,curf);
}

void dk(){
     cin>>w>>f;
     cin>>n;
     v.assign(n,0);
     inp(v);
     ll sum=accumulate(all(v),0LL);
     ll l=1,r=1e6+10,ans=0;
     while(l<r){
          ll mid=(r-l)/2+l;
          if(check(w*mid,f*mid,sum)){
               ans=mid;
               r=mid;
          }else{
               l=mid+1;
          }
     }
     cout<<ans<<endl;
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