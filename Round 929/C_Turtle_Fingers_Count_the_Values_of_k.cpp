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



map<ll,ll>fact(ll n){
     map<ll,ll>mp;
     for(int i=2;i*i<=n;i++){
          while(n%i==0){
               mp[i]++;
               n/=i;
          }
     }
     if(n>1) mp[n]++;
     return mp;
}

void dk(){
     ll a,b,l;
     cin>>a>>b>>l;
     ll ans=0;
     ll x=1;
     map<ll,ll>mp;
     while(1){
          if(l%x) break;
          ll y=l/x;
          mp[y]++;
          while(y%b==0){
               y/=b;
               ans++;
               mp[y]++;
          }
          x*=a;
     }
     cout<<mp.size()<<endl;
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