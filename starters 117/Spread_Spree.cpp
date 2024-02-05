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
     ll n,m;
     cin>>n>>m;
     ll x=(n+1)/2,y=m/2;
     if(n==m){
          ll ans;
          if(n%2){
               ans=(x*x)%md;
          }else{
               ans=(x*x)%md;
               ans=(ans+(2*x*(x+1))%md)%md;
               ans=(ans+((x+1)*(x+1))%md)%md;
          }
          cout<<ans<<endl;
          return;
     }
     if(m>n) swap(n,m);
     x=n/2;
     
     ll mn=max(m-(x+1),0LL);
     ll mx=min(x+1,m);
     ll sum=(mx*(mx+1))/2-(mn*(mn+1))/2;
     
     if(n%2) x++;
     sum%=md;
     ll ans=(x*sum)%md;

     if(n%2==0){
          x++;
          ans=(ans+(x*sum)%md)%md;
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