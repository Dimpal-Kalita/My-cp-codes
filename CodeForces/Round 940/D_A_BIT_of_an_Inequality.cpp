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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     vl high(n+1,0);
     for(int i=0;i<n;i++){
          for(ll j=31;j>=0;j--){
               if(v[i]&(1LL<<j)){
                    high[i]=j;
                    break;
               }
          }
     }
     ll ans=0;
     for(ll k=31;k>=0;k--){
    
          vector<pll>ps(n+1, {0,0}),ss(n+1,{0,0});
          ll cnt=0;
          ll even=0,odd=0;
          for(ll i=0;i<n;i++){
               if(v[i]&(1LL<<k)){
                    swap(even,odd);
                    odd++;
               }else{        
                    even++;
               }
               ps[i+1]={even,odd};
          }
          even=0,odd=0;
          for(ll i=n-1;i>=0;i--){
               if(v[i]&(1LL<<k)){
                    swap(even,odd);
                    odd++;
               }else{        
                    even++;
               }
               ss[i]={even,odd};
          }
          for(ll i=0;i<n;i++){
               if(high[i]!=k) continue;
               ans+=(ps[i].S*(ss[i+1].F+1));
               ans+=((ps[i].F+1)*ss[i+1].S);
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