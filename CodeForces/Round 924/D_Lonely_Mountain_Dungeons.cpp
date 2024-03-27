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
     ll n,b,x;
     cin>>n>>b>>x;
     vl v(n);
     inp(v);
     auto calc=[&](ll m){
          ll ans=0;
          for(auto x:v){
               ll t=x/m;
               ll extra=x%m;
               ll nextra=m-extra;
               if(x<m) nextra=0;
               ans+=(t+1)*(extra*(extra-1)/2)*(t+1)+t*(nextra*(nextra-1)/2)*t;
               ans+=(t+1)*extra*t*nextra;
          }
          return ans*b-(m-1)*x;
     };
     ll l=1,r=*max_element(all(v))+2,ans=0;
     while(l<r){
          ll mid=(l+r)/2;
          if(calc(mid)<calc(mid+1)){
               ans=calc(mid+1);
               l=mid+1;
          }else{
               r=mid;
          }
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