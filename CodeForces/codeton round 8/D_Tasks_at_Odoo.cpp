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
     ll n,t;
     cin>>n>>t;
     vl v(n);
     inp(v);
     auto check=[&](ll k)->bool{
          priority_queue<ll,vector<ll>,greater<ll>> pq;
          rep(i,0,k) pq.push(0);
          for(auto i:v){
               ll x=pq.top();
               pq.pop();
               if(x+i>t) return 0;
               pq.push(x+i);
          }
          return 1;
     };
     ll l=1,r=n+1,ans=-1;
     while(l<r){
          ll m=(l+r)/2;
          if(check(m)){
               ans=m;
               r=m;
          }else{
               l=m+1;
          }
     }
     cout<<ans<<endl;
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