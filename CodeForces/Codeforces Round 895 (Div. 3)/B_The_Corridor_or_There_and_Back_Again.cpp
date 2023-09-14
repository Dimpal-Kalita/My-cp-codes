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
     vector<pll>v(n);
     for(auto &it:v){
          cin>>it.F>>it.S;
     } 
     sort(all(v));

     auto check=[&](ll mid)->bool{
          for(auto i:v){
               if((mid-i.F)*2<i.S) continue;
               else return false;
          }
          return true;
     };

     ll l=0,r=1e5;
     while(l<r){
          ll mid=(l+r)/2;
          if(check(mid)){
               l=mid+1;
          }
          else r=mid;
     }
     cout<<r-1<<endl;
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