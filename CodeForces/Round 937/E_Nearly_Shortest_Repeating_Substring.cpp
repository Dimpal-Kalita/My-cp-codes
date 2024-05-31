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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n;
     cin>>n;
     string s;
     cin>>s;

     function<bool(ll)> check=[&](ll len)->bool{
          if(len==n) return 1;
          map<string,ll>mp;
          for(int i=0;i<n;i+=len){
               mp[s.substr(i,len)]++;
          }
          if(sz(mp)==1) return 1;
          if(sz(mp)>2) return 0;
          string a,b;
          for(auto [x,y]:mp){
               if(y==1 and a.empty()){
                    a=x;
                    continue;
               }
               else if(y==(n/len)-1){
                    b=x;
                    continue;
               }else 
                    return 0;
          }
          ll ct=0;
          for(int i=0;i<len;i++){
               if(a[i]!=b[i]) ct++;
          }
          if(ct==1) return 1;
          return 0;
     };
     ll ans=n;
     for(ll i=1;i*i<=n;i++){
          if(n%i==0){
               if(check(i)){
                    ans=min(ans,i);
               }
               if(check(n/i)){
                    ans=min(ans,n/i);
               }
          }
     }
     cout<<ans<<endl;
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