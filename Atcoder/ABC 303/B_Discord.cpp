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
     ll n,m;
     cin>>n>>m;
     vector<pll> tot;
     for(int i=1;i<=n;i++){
          for(int j=i+1;j<=n;j++){
               tot.pb({i,j});
          }
     }

     sort(all(tot));
     vector<ll> vis(tot.size(),0);
     while(m--){
          vector<ll> v(n);
          inp(v);
          for(int i=1;i<n;i++){
               pll p={v[i-1],v[i]};
               if(p.F>p.S) swap(p.F,p.S);
               ll ind=lower_bound(all(tot),p)-tot.begin();
               vis[ind]=1;
          }
     }

     ll ans=0;
     for(auto it:vis){
          if(!it) ans++;
     }

     cout<<ans<<endl;
      

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