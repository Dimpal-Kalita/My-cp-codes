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
     map<ll,pll>mp;
     ll mx=0;
     rep(i,0,n){
          cin>>v[i];
     }
     rep(i,1,n){
          if(v[i-1]!=v[i]){
               mp[i+1]={i,i+1};
          }else{
               if(mp.count(i)){
                    mp[i+1]=mp[i];
               }
          }
     }
     ll q;
     cin>>q;
     rep(i,0,q){
          ll l,r;
          cin>>l>>r;
          if(mp.count(r) and mp[r].F>=l){
               cout<<mp[r].F<<" "<<mp[r].S<<endl;
          }else{
               cout<<"-1"<<" "<<"-1"<<endl;
          }
     }
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