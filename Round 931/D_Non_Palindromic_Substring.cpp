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
     ll n,q;
     cin>>n>>q;
     string s;
     cin>>s;
     vl v;
     rep(i,0,n-1){
          if(s[i]!=s[i+1]) v.pb(i);
     }
     vl vp;
     rep(i,1,n-1){
          if(s[i-1]!=s[i+1]) vp.pb(i);
     }
     while(q--){
          ll l,r;
          cin>>l>>r;
          l--,r--;
          ll mid=(l+r)/2;
          ll x=lower_bound(all(v),mid)-v.begin();
          if(x+1>r){
               
          }
          auto ind=lower_bound(all(vp),l);
          ind--;
          ll y=ind-vp.begin();
          if(y-1<l){
          
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