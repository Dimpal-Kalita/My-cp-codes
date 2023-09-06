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
     ll mn=1e12,cur=0;
     ll last=0,sum=0;
     map<ll,vl>mp;
     for(auto i:v){
          cur+=i;
          sum+=i;
          if(cur>0){
               last=sum;
               cur=0; 
          }
          if(mn>=cur){
               mn=cur;
               mp[mn].pb(last);
          }
     }
     ll mx=0,ind=0;
     for(auto i:mp[mn]){
          mx=max(mx,i-ind*mn);
     }
     cout<<mx<<endl;
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