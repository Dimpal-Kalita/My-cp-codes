/**
 * 
 * author: Dimpal Kalita
 * date: 19/05/2023 23:46:37
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
      vector<ll> v(n);
      rep(i,0,n){
          cin>>v[i];
      }
      ll mn=1e7,mx=-1e7,ans=1e7;
      for(int i=0;i<n;i++){
          ll tx=max(mx,v[i]-x);
          ll tn=min(mn,v[i]-x);
          
          tx=max(mx,v[i]+x);
          tn=min(mn,v[i]+x);
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