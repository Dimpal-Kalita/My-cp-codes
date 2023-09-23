#include<bits/stdc++.h>
using namespace std;

#define md                  998244353
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
     ll q,k;
     cin>>q>>k;
     vl dp(k+1,0);
     dp[0]=1;
     while(q--){
          char c;
          ll x;
          cin>>c>>x;
          if(c=='+'){
               for(int i=k;i>=x;i--){
                    dp[i]=(dp[i]+dp[i-x])%md;
               }
          }else{
                for(int i=x;i<=k;i++){
                    dp[i]=(dp[i]-dp[i-x]+md)%md;
               }
          }
          cout<<dp[k]<<endl;
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