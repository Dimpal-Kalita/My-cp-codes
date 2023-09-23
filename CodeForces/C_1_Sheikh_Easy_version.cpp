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
     ll n,q;
     cin>>n>>q;
     vl v(n);
     inp(v);
     vl ps(n+1,0),px(n+1,0);
     rep(i,0,n){
          ps[i+1]=ps[i]+v[i];
          px[i+1]=px[i]^v[i];
     }
     auto sum=[&](int l,int r){
          return ps[r]-ps[l-1];
     };
     auto xor_=[&](int l,int r){
          return px[r]^px[l-1];
     };
     ll l,r;
     cin>>l>>r;
     ll mx=sum(l,r)-xor_(l,r);
     pll ans={l,r};
     
     ll low=0,high=r-l+2;
     while(low<high){
          ll mid=(low+high)>>1;
          bool flag=0;
          for(int i=l+mid;i<=r;i++){
               ll x=sum(i-mid,i)-xor_(i-mid,i);
               if(x==mx){
                    flag=1;
                    ans.F=i-mid;
                    ans.S=i;
               }
          }
          if(flag){
               high=mid;
          }else{
               low=mid+1;
          }
     }
     cout<<ans.F<<" "<<ans.S<<endl;
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