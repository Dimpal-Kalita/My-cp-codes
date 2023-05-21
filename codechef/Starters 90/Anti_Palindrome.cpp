/**
 * 
 * author: Dimpal Kalita
 * date: 17/05/2023 20:08:27
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
      map<char,ll> mp;
      for(auto it:s){
          mp[it]++;
      }
      ll ct=0;
      for(auto [x,y]:mp){
          if(y%2) ct++;
      }
      if(ct>=2){
          cout<<0<<endl;
          return;
      }
      if(n%2==0){
          cout<<((ct>0)?0:1)<<endl;
          return;
      }

     auto all_equal = [](string s){
          for(int i=1;i<s.size();i++){
          if(s[i]!=s[i-1]) return false;
          }
          return true;
     };
      if(all_equal(s)){
          cout<<2<<endl;
          return;
      }
      ll ct2=0;
      for(char i='a';i<='z';i++){
          if(mp[i]==0){
               cout<<1<<endl;
               return;
          }
      }

      for(auto [x,y]:mp){
          if(y%2==0) ct2++;
      }
      if(ct2>=2){
          cout<<1<<endl;
          return;
      }

      cout<<2<<endl;

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