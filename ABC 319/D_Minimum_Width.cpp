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
     ll n,m;
     cin>>n>>m;
     vl v(n);
     inp(v);
     ll mx=*max_element(all(v));
     
     auto check=[&](ll w)->bool{
          if(mx>w) return 0;
          ll curlen=w,ct=1;
          for(auto i:v){
               if(curlen-i>=0){
                    curlen-=(i+1);
               }else{
                    ct++;
                    curlen=w-(i+1);
               }
          }
          return ct<=m;
     };
     
     ll l=0,r=1e16;
     while(l<r){
          ll mid=(r-l)/2+l;
          if(check(mid)){
               r=mid;
          }else{
               l=mid+1;
          }
     }
     cout<<r<<endl;
}



int main()
{ 
    fast_io;
  
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}