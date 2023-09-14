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


void dk(){
     ll n,k,a,b;
     cin>>n>>k>>a>>b;
     vector<pll>v(n);
     for(auto &it:v){
          cin>>it.F>>it.S;
     }

     pll x=v[a-1],y=v[b-1];
     ll mn1=1e14,mn2=1e14;
     for(int i=0;i<k;i++){
          mn1=min(mn1,abs(x.F-v[i].F)+abs(x.S-v[i].S));
          mn2=min(mn2,abs(y.F-v[i].F)+abs(y.S-v[i].S));
     }
     ll ans=min(mn1+mn2,abs(x.F-y.F)+abs(x.S-y.S));
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