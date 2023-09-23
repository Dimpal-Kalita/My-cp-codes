/**
 * 
 * author: Dimpal Kalita
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


void dk(){
     ll n,H;
     cin>>n>>H;
     vl v(n);
     inp(v);

     auto check=[&](ll x)->bool{
        ll h=H;
        for(auto i:v){
            if(i>x){
                if(h<=i) return 0;
                h-=i;
            }
        }
        return h>0;
     };

     ll l=0,r=1e14;
     ll ans=0;
     while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
            ans=mid;
        }else{
            l=mid+1;
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