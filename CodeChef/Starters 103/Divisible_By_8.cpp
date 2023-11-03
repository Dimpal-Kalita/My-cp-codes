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


ll count(string s,string t){
     ll ct=0;
     for(int i=0;i<s.length();i++){
          if(s[i]!=t[i]) ct++;
     }
     return ct;
}

void dk(){
     ll n;
     cin>>n;
     string s;
     cin>>s;
     if(n==1){
          ll x=s[0]-'0';
          if(x%8){
               cout<<8<<endl;
          }else{
               cout<<x<<endl;
          }
          return;
     }
     if(n==2){
          ll mn=20;
          string ans="";
          for(int i=10;i<=99;i++){
               if(i%8==0){
                    ll ct=count(to_string(i),s);
                    if(ct<mn){
                         mn=ct;
                         ans=to_string(i);
                    }
               }
          }
          cout<<ans<<endl;
          return;
     }
     string t=s.substr(n-3,3);
     // cout<<t<<endl;
     ll mn=20;
     string ans=t;
     if(stoi(t)%8==0){
          cout<<s<<endl;
          return;
     }
     for(int i=0;i<=9;i++){
          t[2]=i+'0';
          ll x=stoi(t);
          if(x%8==0){
               ans=t;
          }
     }
     s[n-3]=ans[0],s[n-2]=ans[1],s[n-1]=ans[2];
     cout<<s<<endl;
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