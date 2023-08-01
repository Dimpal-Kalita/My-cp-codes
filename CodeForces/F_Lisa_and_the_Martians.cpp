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


typedef struct Ans{
     int i,j,x;
} Ans;


void dk(){
     ll n,k;
     cin>>n>>k;
     vector<pll>vp;
     rep(i,0,n){
          ll x;
          cin>>x;
          vp.pb({x,i});
     }
     Ans ans;
     sort(all(vp));
     ll mx=-1;
     rep(i,0,n-1){
          ll x=0;
          for(int j=0;j<k;j++){
               ll t=1ll<<j;
               if(!(vp[i].F&t) and !(vp[i+1].F&t)){
                    x|=t;
               }
          }
          ll val=(vp[i].F^x) &  (vp[i+1].F^x); 
          if(val>mx){
               mx=val;
               ans.i=vp[i].S+1;
               ans.j=vp[i+1].S+1;
               ans.x=x;
          }
     }
     cout<<ans.i<<" "<<ans.j<<" "<<ans.x<<endl; 
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