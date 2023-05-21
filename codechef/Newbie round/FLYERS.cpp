/**
 * 
 * author: Dimpal Kalita
 * date: 15/05/2023 21:05:34
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
      ll n,x;
      cin>>n>>x;
      vector<pair<ll,pll>>vp(n);
      rep(i,0,n){
          cin>>vp[i].S.F;
      }
      rep(i,0,n){
          cin>>vp[i].S.S;
      }
      rep(i,0,n){
          vp[i].F=vp[i].S.S/vp[i].S.F;
      }
      sort(all(vp));
      ll ans=0;
      rep(i,0,n){
          ll val= min(vp[i].S.F,x/vp[i].F);
          ans+=val;
          x-= val*vp[i].F;
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