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
     string s;
     cin>>s;
     ll neq=0;
     for(int i=0;i<n/2;i++){
          if(s[i]!=s[n-i-1]) neq++;
     }
     if(n%2){
          for(int i=0;i<neq;i++){
               cout<<0;
          }
          for(int i=neq;i<=n-neq;i++){
               cout<<1;
          }
          for(int i=n-neq;i<n;i++){
               cout<<0;
          }
          cout<<endl;
          return;
     }
     for(int i=0;i<neq;i++){
          cout<<0;
     }
     bool one=1;
     for(int i=neq;i<=n-neq;i++){
          cout<<one;
          one^=1;
     }
     for(int i=n-neq;i<n;i++){
          cout<<0;
     }
     cout<<endl;
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