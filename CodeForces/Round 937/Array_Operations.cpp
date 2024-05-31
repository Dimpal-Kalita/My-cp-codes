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
     ll n,k;
     cin>>n>>k;
     vl v(n);
     inp(v);
     function<bool(ll mid)> check=[&](ll mid)->bool{
          multiset<ll,greater<ll>>mx,mn;
          rep(i,0,n){
               if(v[i]>=mid) mx.insert(v[i]);
               else mn.insert(v[i]);
          }
          ll x=mid;
          while(x and !mn.empty() and !mx.empty() and mx.size()<x){
               auto val=*mx.begin();
               mx.erase(mx.find(val));
               if(val%k==0 and (val/k)>=mid){
                    auto val2=*mn.begin();
                    mn.erase(mn.find(val2));
                    if(val2%k==0){
                         continue;
                    }
                    if(val2*k>=mid){
                         x--;
                    }else{
                         mn.insert(val2*k);
                    }
                    mx.insert(val/k);
               }else{
                    x--;
               }
          }
          // debug(mx);
          if(x==0) return 1;
          for(auto it:mx){
               if(it>=mid) x--;
               if(x==0) return 1;
          }
          return 0;
     };
     // cout<<check(3)<<endl;
     ll l=0,r=n+1,ans=0;
     while(l<r){
          ll mid=(l+r)/2;
          if(check(mid)){
               ans=mid;
               l=mid+1;
          }
          else r=mid;
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