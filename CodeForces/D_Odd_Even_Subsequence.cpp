/**
 * 
 * author: Dimpal Kalita
 * date: 19/05/2023 13:49:11
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

ll n,k;
vl v;


bool check(ll x){
     ll ct=0,ev=0,od=0;
     for(int i=0;i<n;i++){
          if(ct%2==0){
               ct++;
               ev++;
          }
          else {
               if(v[i]<=x){
                    ct++;
                    od++;
               }
          }
     }
     if(ev+od>=k) return 1;

     ct=0,ev=0,od=0;
     for(int i=0;i<n;i++){
          if(ct%2==1){
               ct++;
               od++;
          }
          else {
              if(v[i]<=x){
                    ct++;
                    ev++;
               }
          }
     }

     return ev+od>=k;
}

void dk(){
      cin>>n>>k;
      v.resize(n);
      inp(v);
      ll l=1,r=1e10;
      while(l<r){
           ll m= (l+r)/2;
           if(check(m)){
                r=m;
           }else{
                l=m+1;
           }
      }
      cout<<l<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}