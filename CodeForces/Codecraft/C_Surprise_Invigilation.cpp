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
     vl a(n),b(n);
     map<ll,ll>mp;
     rep(i,0,n){
          ll x;
          cin>>x;
          mp[x]++;
          a[i]=x;
     }
     rep(i,0,n){
          ll x;
          cin>>x;
          b[i]=x;
          x++;
          mp[x]--;
     }
     sort(all(a));
     sort(all(b));
     ll q;
     cin>>q;
     vector<pll>vp;
     rep(i,0,q){
          ll x;
          cin>>x;
          vp.pb({x,i});
     }
     sort(all(vp));
     vl ans(q);
     ll ct=0,j=0,k=0;
     for(auto x:vp){
          while(j<n and a[j]<=x.F){
               // cout<<a[j]<<endl;
               j++;
               ct++;
          }
          while(k<n and b[k]<x.F){
               k++;
               ct--;
          }
          // cout<<x.F<<" "<<ct<<endl;
          ans[x.S]=ct;
     }
     for(auto x:ans) cout<<x<<" ";
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