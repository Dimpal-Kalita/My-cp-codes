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


bool isPalindrom(string s){
     int n=s.length();
     for(int i=0;i<n/2;i++){
          if(s[i]!=s[n-i-1]) return false;
     }
     return true;
}

void dk(){
      string s;
      cin>>s;
      ll n=s.length();
      int ans=0;
      for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
               if(isPalindrom(s.substr(i,j-i+1))){
                    ans=max(ans,j-i+1);
               }
          }
      }
      cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}