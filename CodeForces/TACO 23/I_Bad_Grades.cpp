/**
 * 
 * author: Dimpal Kalita
 * date: 22/05/2023 14:14:30
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
      string s;
      cin>>s;
      bool less=0;
      for(auto &it:s){
          if(less==1){
               it='9';
               continue;
          }
          if(it=='7'){
               it--;
               less=1;
          }
      }
      
      if(less==0){
          s[s.length()-1]--;
          if(s[s.length()-1]=='7'){
               s[s.length()-1]--;
          }
      }
      cout<<s<<endl;
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