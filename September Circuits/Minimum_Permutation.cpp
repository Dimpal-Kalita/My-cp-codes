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
     vl v(n);
     inp(v);
     vl rev=v;
     reverse(all(rev));
     if(!is_sorted(all(rev))){
          cout<<0<<endl;
          return;
     }
     for(int i=n-1;i>=0;i--){
          if(rev[i]>i+1){
               cout<<0<<endl;
               return;
          }
     }
     ll ans=1,ct=n;
     for(int i=1;i<n;i++){
          // cout<<ct-v[i]<<endl;
          if(v[i]==v[i-1]){
               ans*=(ct-v[i]);
               ans%=md;
          }
          ct--;
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