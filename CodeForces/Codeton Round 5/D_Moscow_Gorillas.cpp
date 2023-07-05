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


void dk(){
     ll n;
     cin>>n;
     vl a(n+1), b(n+1),posa(n+1),posb(n+1);
     rep(i,1,n+1){
          cin>>a[i];
          posa[a[i]]=i;
     }
     rep(i,1,n+1){
          cin>>b[i];
          posb[b[i]]=i;
     }
     ll ans=0, l=min(posa[1],posb[1]), r=max(posa[1],posb[1]), x=r-l-1;
     ans+= l*(l-1)/2 + x*(x+1)/2 + (n-r+1)*(n-r)/2;
     // cout<<ans<<endl;
     rep(mex,2,n+1){
          ll x=min(posa[mex],posb[mex]), y=max(posa[mex],posb[mex]);
          if((posa[mex]>=l && posa[mex]<=r) || (posb[mex]>=l && posb[mex]<=r)){
               l=min(l,x);
               r=max(r,y);
          }
          else{
               if((x<=l and y<=l)){
                    ans+=(l-y)*(n-r+1);
               }
               else if((x>=r and y>=r)){
                    ans+=(x-r)*l;
               }
               else{
                    ans+=(l-x)*(y-r);
               }
               l=min(l,x);
               r=max(r,y);
          }
     }
     cout<<ans+1<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}