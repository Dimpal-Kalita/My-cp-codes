#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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




bool check(vector<ll>&v,ll ind){
     ll n=v.size();
     vl a;
     rep(i,0,n-1){
          if(i!=ind and i+1!=ind) a.pb(gcd(v[i],v[i+1]));
          else if(i==ind){
               if(i-1>=0) a.pb(gcd(v[i-1],v[i+1]));
          }else{
               if(i+2<n) a.pb(gcd(v[i],v[i+2]));
          }
     }
     // debug(ind,a);
     return is_sorted(all(a));
}

void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     set<ll>ind;
     rep(i,1,n-1){
          if(gcd(v[i],v[i-1])>gcd(v[i],v[i+1])){
               ind.insert(i);
               ind.insert(i+1);
               ind.insert(i-1);
          }
     }
     ind.insert(0);
     ind.insert(n-1);
     // debug(ind);
     if(ind.size()>10){
          cout<<"NO"<<endl;
          return;
     }
     for(auto i:ind){
          if(check(v,i)){
               cout<<"YES"<<endl;
               return;
          }
     } 
     cout<<"NO"<<endl;
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