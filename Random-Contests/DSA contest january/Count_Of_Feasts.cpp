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

const int N=1e5+1;

void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     vl dp(N+1,-1);
     function<ll(ll)>recur=[&](ll sum)->ll{
          if(sum==0) return 1;
          if(dp[sum]!=-1) return dp[sum];
          ll ans=0;
          for(auto x:v){
               if(sum>=x) ans=(ans+recur(sum-x))%md;
          }
          return dp[sum]=ans;
     };
     vl ps(N+1);
     rep(i,1,N){
          ps[i]=(ps[i-1]+recur(i))%md;
     }
     ll q;
     cin>>q;
     while(q--){
          ll l,r;
          cin>>l>>r;
          cout<<(ps[r]-ps[l-1]+md)%md<<endl;
     }
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