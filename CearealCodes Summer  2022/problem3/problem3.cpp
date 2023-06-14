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


ll n,h,k;
vector<pll>v;

bool check(lld R, ll x, ll y){
    ll n=v.size();
    if(x-R<=0 || x+R>=h) return false;
    if(y-R<=0 || y+R>=h) return false;
    for(int i=0;i<n;i++){
      lld dist=(v[i].F-x)*(v[i].F-x)+(v[i].S-y)*(v[i].S-y);
      if(dist<=R*R) return false;
    }
    return true;
}


void dk(){
    cin>>h>>k>>n;
    rep(i,0,n){
      int x,y;
      cin>>x>>y;
      v.pb({x,y});
    }
    lld ans=0;
    for(int x=0;x<=h;x++){
      for(int y=0;y<=k;y++){
        
            ll mn=200;
            lld l=0,r=mn;

            while(r-l>1e-9){
              lld mid=(l+r)/2;
              if(check(mid,x,y)){
                  l=mid;
              }
              else{
                  r=mid;
              }
            }

            ans=max(ans,l);
      }
    }

    cout<<fixed<<setprecision(9)<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}