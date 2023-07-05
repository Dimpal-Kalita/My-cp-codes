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
      ll n;
      cin>>n;
      ll prod=1;
      vector<ll> v;
      for(ll i=1;i<n;i++){
          if(gcd(i,n)==1){
               v.pb(i);
          }
      }
      ll mx=1;
      ll ct=0;
      for(auto it:v){
          ct++;
          prod=(prod*it)%n;
          if(prod==1){
               mx=ct;
          }
      }
      cout<<mx<<endl;
      for(int i=0;i<mx;i++){
          cout<<v[i]<<" ";
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