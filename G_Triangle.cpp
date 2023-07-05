/**
 * 
 * author: Dimpal Kalita
 * date: 29/06/2023 14:12:31
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


bool checkHappy(ll n){
     string s=to_string(n);
     while(s.length()>1){
          ll x=0;
          for(auto it:s){
               x+= (it-'0')*(it-'0');
          }
          s=to_string(x);
     }
     return s=="1" or s=="7";
}

void dk(){
      ll n;
      cin>>n;
      ll x=n+1;
      while(1){
          if(checkHappy(x)){
               cout<<x<<endl;
               return;
          }
          x++;
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