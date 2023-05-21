/**
 * 
 * author: Dimpal Kalita
 * date: 29/04/2023 18:30:11
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  998244353
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




void dk(){
      ll n;
      cin>>n;
      vector<ll> v={2,3,5};
      map<ll,ll> mp;
      while(n>1){
          for(auto it:v){
               if(n%it==0){
                    n/=it;
                    mp[it]++;
               }
          }
      }
      ll ans=1;
      ll ct=0;
      for(auto it:mp){
         
      }
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