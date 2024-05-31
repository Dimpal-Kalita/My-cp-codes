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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n,x,y;
     cin>>n>>x>>y;
     vl v(x);
     inp(v);
     sort(all(v));
     ll ans=max(x-2,0LL);
     vl even,odd;
     rep(i,0,x-1){
          ll dif=v[i+1]-v[i];    
          if(dif==2) ans++;
          else{
               if(dif<2) continue;
               if(dif%2==0) even.pb(dif);
               else odd.pb(dif);
          }
     }
     ll dif=n-v.back()+v[0];
     if(dif==2) ans++;
     else{
          if(dif<2) ;
          else{
               if(dif%2==0) even.pb(dif);
               else odd.pb(dif);
          }
     }
     sort(all(even));
     sort(all(odd));
     vl viseven(sz(even)+1),visodd(sz(odd)+1);
     rep(i,0,sz(even)){
          ll x=even[i]/2-1;
          if(y>=x){
               y-=x;
               ans+=(even[i]-1);
               viseven[i]=1;
          }else{
               break;
          }
     }
     rep(i,0,sz(odd)){
          ll x=odd[i]/2;
          if(y>=x){
               y-=x;
               ans+=(odd[i]-1);
               visodd[i]=1;
          }else{
               break;
          }
     }
     for(int i=0;i<sz(even);i++){
          if(viseven[i]==0 and y){
               ans+=2*y;
               y=0;
               break;
          }
     }
     for(int i=0;i<sz(odd);i++){
          if(visodd[i]==0 and y){
               ans+=2*y;
               y=0;
               break;
          }
     }
     cout<<ans<<endl;
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