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

vl vp;

void pre(){
     vp.pb(0);
     rep(i,1,513){
          vp.pb(i*i);
     }
}
void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     ll ans=0;
     for(auto x:vp){
          if(x>2*n+2) break;
          vl mp(2*max(x,n)+2,0);
          ll y=0;
          mp[0]++;
          for(auto i:v){
               y^=i;
               ans+=mp[y^x];
               mp[y]++;
          }
     }
     cout<<(n*(n+1))/2-ans<<endl;
}



int main()
{ 
    fast_io;
    pre();
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   