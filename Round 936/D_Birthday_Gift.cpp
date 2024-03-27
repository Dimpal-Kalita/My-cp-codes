#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (ll)(x).size()   
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
     ll n,x;
     cin>>n>>x;
     vl v(n);
     inp(v);
     vl cur=v;
     ll ans=-1;
     for(ll i=30;i>=0;i--){
          ll mask=(1LL<<i);
          vl temp;
          ll val=cur.front();
          for(int i=1;i<sz(cur);i++){
               ll j=cur[i];
               if(val&mask){
                    val^=j;
               }
               else{
                    temp.pb(val);
                    val=j;
               }
          }
          temp.pb(val);
          // debug(temp);
          // debug(i);
          if(x&mask){
               if(!(val&mask)){
                    ans=max(ans,sz(temp));
               }
          }else{
               if(!(val&mask)){
                    cur=temp;
               }else{    
                    cout<<ans<<endl;
                    return;
               }
          }
     }
     cout<<max(ans,sz(cur))<<endl;
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