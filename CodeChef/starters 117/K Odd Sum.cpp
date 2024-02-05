/**
 * 
 * author: Dimpal Kalita
 * date: 31/01/2024 21:14:31
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
      ll n,k;
      cin>>n>>k;
      vl ans;
      ans.pb(1);
      ll start=2;
      while(k--){
          ans.pb(start++);
      }
      ll odd=(start%2?start:start+1);
      ll even=(start%2==0?start:start+1);
      if(ans.back()%2==0){
          ll x=ans.back();
          ans.pop_back();
          while(odd<=n){
               ans.pb(odd);
               odd+=2;
          }
          ans.push_back(x);
          while(even<=n){
               ans.pb(even);
               even+=2;
          }
      }else{
          ll x=ans.back();
          ans.pop_back();
          while(even<=n){
               ans.pb(even);
               even+=2;
          }
          ans.push_back(x);
          while(odd<=n){
               ans.pb(odd);
               odd+=2;
          }
      }
      for(auto i:ans)cout<<i<<" ";
      cout<<endl;
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