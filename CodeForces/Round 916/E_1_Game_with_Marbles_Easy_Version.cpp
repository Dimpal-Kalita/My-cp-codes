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
     vl v1(n),v2(n);
     inp(v1);
     inp(v2);
     vector<array<ll,3>>vp;
     rep(i,0,n){
          vp.pb({v1[i]+v2[i],v1[i]-1,v2[i]-1});
     }
     sort(all(vp),greater<array<ll,3>>());
     ll A=0,B=0;
     for(int i=0;i<n;i++){
          if(i%2==0){
               A+=vp[i][1];
          }
          else{
               B+=vp[i][2];    
          }
     }
     cout<<A-B<<endl;
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