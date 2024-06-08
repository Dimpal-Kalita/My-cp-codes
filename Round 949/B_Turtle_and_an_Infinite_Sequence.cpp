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

ll MSB(ll n){
     ll x=-1;
     while(n){
          n>>=1;
          x++;
     }
     return x;
}

ll bitOr(ll l,ll r){
     ll ans=0;
     ll msb1=MSB(l),msb2=MSB(r);
     while(msb1==msb2){
          if(l==0 or r==0) break;
          ans+=(1LL<<msb1);
          l-=(1LL<<msb1);
          r-=(1LL<<msb1);
          msb1=MSB(l);
          msb2=MSB(r);
     }
     msb1=max(msb1,msb2);
     for(ll i=msb1;i>=0;i--){
          ans+=(1LL<<i);
     }
     return ans;
}

void dk(){
     ll n,m;
     cin>>n>>m;
     ll ans=0;
     ll l=max(0LL,n-m),r=n+m;
     cout<<bitOr(l,r)<<endl;
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