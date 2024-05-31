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
     vl v;
     for(ll i=0;i<31;i++){
          if(n&(1LL<<i)){
               v.pb(1);
          }else{
               v.pb(0);
          }
     }
     v.pb(0);
     ll last=0;
     vl ans(32);
     for(ll i=0;i<31;i++){
          if(v[i]==0){
               continue;
          }
          ll ind=i;
          while(ind<v.size() and v[ind]==1) ind++;
          if(ind-i==1){
               ans[i]=1;
               i=ind;
               continue;
          }
          ans[ind]=1;
          ans[i]=-1;
          i=ind-1;
          v[ind]=1;
     }
     cout<<ans.size()<<endl;
     for(auto x: ans){
          cout<<x<<" ";
     }
     cout<<endl;
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