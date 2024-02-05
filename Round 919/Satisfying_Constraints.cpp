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
     ll l=1,r=1e9+1;
     map<ll,ll>mp;
     rep(i,0,n){
          ll a,b;
          cin>>a>>b;
          if(a==1){
               l=max(l,b);
          }else if(a==2){
               r=min(r,b);
          }else{
               mp[b]=1;
          }
     }
     ll ans=r-l+1;
     for(auto [x,y]:mp){
          if(x>=l and x<=r) ans--;
     }
     cout<<max(0LL,ans)<<endl;
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