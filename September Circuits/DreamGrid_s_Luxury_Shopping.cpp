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

     auto check=[&](ll money){
          ll ct=0;
          for(auto i:v){
               if(i<=money){
                    ct++;
                    money-=i;
               }
          }
          return ct<=m;
     };

     ll sum=0;
     rep(i,0,m) sum+=v[i];
     ll l=sum,r=1e15,ans=0;
     while(l<r){
          ll mid=(r-l)/2+l;
          if(check(mid)){
               ans=mid;
               l=mid+1;
          }
          else{
               r=mid;
          }
     }
     cout<<max(ans,sum)<<endl;
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