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
     string s;
     cin>>s;
     vl ss(n+1);
     for(int i=n-1;i>=0;i--){
         ss[i]=ss[i+1]+(s[i]=='1');
     }
     ll left=0;
     vector<pair<ll,ll>>ans;
     for(ll i=0;i<n;i++){
          left+=(s[i]=='0');
          ll right=ss[i+1];
          ll tot_right=n-i-1;
          if(right>=ceil(tot_right/2.0)){
              ll tot_left=i+1;
              if(left>=ceil(tot_left/2.0)){
               // cout<<i+1<<" "<<n/2-i<<endl;
                  ans.pb({abs(n/2-(i+1)),i+1});
              }
          }
     }
     sort(all(ans));
     debug(ans);
     if(sz(ans)){
         cout<<ans[0].S<<endl;
     }
     else
          cout<<0<<endl;
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