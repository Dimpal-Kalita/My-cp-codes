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
     vector<pll>vp;
     rep(i,0,n){
          ll x;
          cin>>x;
          vp.pb({x,1});
     }
     rep(i,0,m){
          ll x;
          cin>>x;
          vp.pb({x,2});
     }
     sort(all(vp));
     rep(i,0,n+m-1){
          if(vp[i].S==vp[i+1].S and vp[i].S==1){
               cout<<"Yes"<<endl;
               return;
          }
     }
     cout<<"No"<<endl;
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