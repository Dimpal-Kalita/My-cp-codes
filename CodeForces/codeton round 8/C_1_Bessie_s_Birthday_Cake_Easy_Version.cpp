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


ll dif(ll x,ll y,ll n){
     return min(x+n-y,y-x);
}

void dk(){
     ll n,x,y;
     cin>>n>>x>>y;
     vl v(x);
     inp(v);
     sort(all(v));
     ll ans=max(x-2,0LL);
     rep(i,0,x-1){    
          if(v[i+1]-v[i]==2) ans++;
     }
     if(v[0]+n-v.back()==2) ans++;
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