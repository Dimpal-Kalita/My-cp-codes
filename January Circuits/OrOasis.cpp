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
     vector<vl> ps(n+1,vl(32,0));
     ll total=0;
     rep(i,0,n){
          rep(j,0,32){
               ps[i+1][j]=ps[i][j]+((v[i]&(1LL<<j))>0);
          }
          total|=v[i];
     }
     auto get=[&](ll l,ll r){
          ll ans=0;
          rep(i,0,32){
               ll cnt=ps[r][i]-ps[l-1][i];
               if(cnt>0){
                    ans|=(1LL<<i);
               }
          }
          return ans;
     };
     auto get_outside=[&](ll l,ll r){
          ll ans=0;
          rep(i,0,32){
               ll cnt=ps[r][i]-ps[l-1][i];
               if(ps[n][i]-cnt>0){
                    ans|=(1LL<<i);
               }
          }
          return ans;
     };
     ll length=0;
     for(ll i=0,j=0;i<n;i++){

     }
     ll cnt=0;
     if(cnt==0){
          cout<<"-1"<<endl;
          return;
     }
     cout<<length<<" "<<cnt<<endl;
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