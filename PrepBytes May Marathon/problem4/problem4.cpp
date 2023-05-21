/**
 * 
 * author: Dimpal Kalita
 * date: 16/05/2023 11:10:29
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


bool isperfect(ll n){
     ll x= sqrt(n);
     return x*x==n;
}

map<ll,ll> mp;

ll recur(ll n){
     
}


void dk(){
      ll n;
      cin>>n;
      vl v(n);
      inp(v);
      map<ll,ll> mp;
      for(int i=0;i<n;i++){
          if(isperfect(v[i])){
               mp[v[i]]++;
          }
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