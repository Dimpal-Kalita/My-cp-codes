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


// 000
// 111
// 100
// 011
// 111 
// 000
// 000
// 000

bool check(string s,string t){
     if(s==t) return 1;
     for(auto &it:s){
          if(it=='1') it='0';
          else it='1';
     }
     if(s==t) return 1;
     return 0;
}


void dk(){
     ll n;
     cin>>n;
     string s,t;
     cin>>s>>t;
     if(!check(s,t)){
          cout<<"NO"<<endl;
          return;
     }
     vector<pll> ans;
     for(int i=0;i<n;i++){
          if(s[i]=='1'){
               ans.pb({i+1,i+1});
          } 
     }
     int ct=ans.size();
     for(int i=0;i<n;i++){
          if(ct%2 and s[i]=='0') t[i]=(t[i]=='1'?'0':'1');
          if(ct%2==0 and s[i]=='1') t[i]=(t[i]=='1'?'0':'1');
     }
     if(count(all(t),'1')==n){
          ans.pb({1,1});
          ans.pb({2,n});
          ans.pb({1,n});
     }
     cout<<"YES"<<endl;
     cout<<ans.size()<<endl;
     for(auto &it:ans){
          cout<<it.F<<" "<<it.S<<endl;
     }
     

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

// 1111 1111
// 0111 1000
// 0011 0011
// 0001 1110
// 0000 0000