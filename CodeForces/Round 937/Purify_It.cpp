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


vl ans(1e6,0);
void solve(){
     ll n=1e5;
     vl vis(n+1,0);
     ans[1]=1;
     map<ll,ll>mp;
     for(ll i=2;i<=n;i++){
          ans[i]+=ans[i-1];
          ll mn=i;
          // for(ll j=2;j*j<=i;j++){
          //      if(i%j==0){
          //           if(lcm(j,i/j)==i){
          //                mn=min(mn,max(j,i/j));    
          //           }
          //      }
          // }
          for(ll j=2;j<i;j++){
               if(lcm(i,j)==i){
                    mn=min(mn,max(j,j));
               }
          }
          ans[i]+=mn;
     }
}

void dk(){
     ll l,r;
     cin>>l>>r;
     cout<<ans[r]<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    solve();
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   