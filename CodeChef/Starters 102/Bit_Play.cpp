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
     ll ans=1;
     for(int i=2;i<n;i+=2){
          ll x=s[i-2]-'0';
          ll y=s[i-1]-'0';
          ll z=s[i]-'0';
          ll ct=0;
          if((x|y)==z) ct++;
          if((x&y)==z) ct++;
          if((x^y)==z) ct++;  
          ans=(ans*ct)%md;
          // cerr<<ct<<" ";
     }
     // cerr<<endl;
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