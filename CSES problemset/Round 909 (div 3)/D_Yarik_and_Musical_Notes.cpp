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


bool poweroftwo(ll n){
     return (n && !(n & (n - 1)));
}

void dk(){
      ll n;
      cin>>n;
      vl v(n);
      map<ll,ll>mp;
      ll ct=0;
      for(auto &i:v){
          cin>>i;
          mp[i]++;
      }
      ll ans=0;
      for(auto [x,y]:mp){
          ans+= (y*(y-1))/2;
      }
      for(ll i=0;i<31;i++){
          for(ll j=i+1;j<31;j++){
               ll x=1ll<<i;
               ll y=1ll<<j;
               if(x*j==y*i){
                    ans+= mp[i]*mp[j];
               }
          }
      }
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