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


ll lcm(ll a,ll b){
     return (a*b)/__gcd(a,b);
}

void dk(){
     ll n;
     cin>>n;
     int v[n];
     rep(i,0,n) cin>>v[i];
     ll x,y;
     cin>>x>>y;
     ll ans=0;
     
     for(int i=0;i<n;i++){
          ull mul=1;
          for(int j=i;j<n;j++){
               mul=lcm(mul,(ull)v[j]);
               if(mul>=x and mul<=y) ans++;
               if(mul>y) break;
          }
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