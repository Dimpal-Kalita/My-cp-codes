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









ll n,k,p;
vector<vl>vp;
map<pair<ll,vl>,ll>mp;

ll recur(ll ind,vl v){

     if(ind==n){
          for(int i=0;i<k;i++){
               if(v[i]<p) return 1e18;
          }
          return 0;
     }

     if(mp.count({ind,v})) return mp[{ind,v}];
     ll np=recur(ind+1,v);

     for(int i=1;i<=k;i++){
          v[i-1]+=vp[ind][i];
          v[i-1]=min(v[i-1],p);
     }
     ll wp=recur(ind+1,v)+vp[ind][0];

     return mp[{ind,v}]=min(np,wp);
}


void dk(){
     cin>>n>>k>>p;
     rep(i,0,n){
          vl v;
          v.resize(k+1);
          inp(v);
          vp.pb(v);
     }
     vl v(k,0);
     ll ans=recur(0,v);
     cout<<(ans>=1e18?-1:ans)<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   