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
     ll ans=1e13;
     ll r=sqrtl(n)+10;
     for(ll i=0;i<=r;i++){
          ll x=i*i;
          ans=min(ans,abs(n-x));
          ll y=n-x;
          ll r2=sqrtl(y);
          for(ll j=max(0LL,r2-1);j<=r2+1;j++){
            ans=min(ans,abs(x+j*j-n));
          }
     } 
     cout<<ans<<endl;

}



int main()
{ 
    fast_io;
    
    int _=1;
    // cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   