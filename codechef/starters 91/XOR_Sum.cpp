/**
 * 
 * author: Dimpal Kalita
 * date: 24/05/2023 21:19:13
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




bool power_of_two(ll x){
     return x && (!(x&(x-1)));
}

ll nearest_power_of_two(ll x){
     ll ans = 1;
     while(ans<x){
          ans <<= 1;
     }
     return ans;
}
void dk(){
      ll l,r;
      cin>>l>>r;
      ll ans=0;
      if(l==0){
          cout<<nearest_power_of_two(r+1)<<endl;
          return;
      }

      for(ll i=0;i<=62;i++){
          ll p=1ll<<i;
          if(l<=p and r>=p){
               ans+= (p-l);
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