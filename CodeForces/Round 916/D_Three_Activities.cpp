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
     vl a(n),b(n),c(n);
     inp(a);
     inp(b);
     inp(c);
     vector<vector<ll>> store(n+1,vector<ll>(8,-1));
     function<ll(ll ind,ll msk)> dp=[&](ll ind,ll msk)->ll{
          if(ind==n || msk==7) return 0;
          if(store[ind][msk]!=-1) return store[ind][msk];
          ll ans=dp(ind+1,msk);
          if(!(msk&1)) ans=max(ans,a[ind]+dp(ind+1,msk|1));
          if(!(msk&2)) ans=max(ans,b[ind]+dp(ind+1,msk|2));
          if(!(msk&4)) ans=max(ans,c[ind]+dp(ind+1,msk|4));
          return store[ind][msk]=ans;
     };
     cout<<dp(0,0)<<endl;
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