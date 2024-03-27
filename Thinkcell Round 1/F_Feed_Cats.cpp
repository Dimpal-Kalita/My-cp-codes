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
     ll n,m;
     cin>>n>>m;
     vector<pll> vp(m);
     map<ll,ll>mp,end,start;
     rep(i,0,m){
          cin>>vp[i].F>>vp[i].S;
          mp[vp[i].F]=max(mp[vp[i].F],vp[i].S);
          end[vp[i].S]++;
          start[vp[i].F]++;
     }
     sort(all(vp));
     ll l=0,r=0;
     vl v(n+1);
     vl nocat(n+1),cat(n+1);
     ll catcount=0;
     for(ll i=1;i<=n;i++){
          if(r==i-1 and !mp.count(i)){
               nocat[i]=1;
          }
          if(start.count(i)){
               catcount+=start[i];
          }
          r=max({r,mp[i],i});
          v[i]=r;
          cat[i]=catcount;
          if(end.count(i)){
               catcount-=end[i];
          }
     }

     vector<ll>dp(n+1,-1);
     function<ll(ll)>recur=[&](ll ind)->ll{
          if(ind==n+1){
               return 0;
          }
          if(dp[ind]!=-1) return dp[ind];
          ll ans=recur(v[ind]+1)+cat[ind];
          ans=max(ans,recur(ind+1));
          return dp[ind]=ans;
     };
     ll ans=recur(1);
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