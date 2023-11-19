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
     ll n,m,k;
     cin>>n>>m>>k;
     vector<vl>v(n+1,vl(m+1));
     rep(i,0,m){
          ll x,y,w;
          cin>>x>>y>>w;
          x--,y--;
          v[x][y]=w;
          v[y][x]=w;
     }
     map<pll,ll>mp;
     ll ans=1e18;
     function<void(ll,ll)> dp=[&](ll mask,ll val){

          if(mask==(1<<n)-1){
               ans=min(ans,val);
               return;
          }
          if(mp.count({mask,val})) return;
          mp[{mask,val}]=1;
          
          rep(i,0,n){
               if((mask&(1<<i))){
                    rep(j,0,n){
                         if(!(mask&(1<<j)) and v[i][j]){
                              dp(mask|(1<<j),(val+v[i][j])%k);
                         }
                    }
               }
          }
     };
     rep(i,0,n){
          dp(1<<i,0);
     }
     cout<<ans<<endl;

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