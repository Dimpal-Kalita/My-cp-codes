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


bool check(vl v,ll mid,ll m){
     ll ind=0,n=v.size();
     for(ll i=0,val=0;i<n;i++){
          ll x = min(mid,v[i]);
          if(x+val<mid){
               val+=x;
               x = 0;
          }else{
               x-=(mid-val);
               val = x;
               x = 0;
               ind++;
          }
          if(ind == m) return 1;
     }
     return ind>=m;
}


void dk(){
     ll n,m;
     cin>>n>>m;
     vector<ll> v(n);
     inp(v);
     ll l=0, r=1e18,ans=0;
     while(l<r){
          ll mid=(r-l)/2+l;
          if(check(v,mid,m)){
               ans=mid;
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
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}