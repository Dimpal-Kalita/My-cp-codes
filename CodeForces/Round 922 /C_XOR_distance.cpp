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
     ll a,b,r;
     cin>>a>>b>>r;
     ll cur=0;
     ll start=0;
     for(ll i=62;i>=0;i--){
          ll x=1ll<<i;
          bool f1=(a&x),f2=(b&x);
          if(f1==f2) continue;
          else{
               if(cur+x>r){
                    if(start) continue;
                    if(f1) start=1;
                    else start=2;
                    continue;
               }
               if(start==1){
                    if(f1) cur+=x;
               }else if(start==2){
                    if(f2) cur+=x;
               }else{
                    if(f1){
                         start=1;
                    }else{
                         start=2;
                    }
               }
          }
     }
     cout<<abs((a^cur)-(b^cur))<<endl;
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