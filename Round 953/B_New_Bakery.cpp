#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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
     ll n,a,b;
     cin>>n>>a>>b;
     ll x=(1+2*b-2*a)/2+1;
     ll y=(1+2*b-2*a)/2;
     ll k1=min({n,b,x});
     ll k2=min({n,b,y});
     k1=max(0LL,k1);
     k2=max(0LL,k2);
     // cout<<k1<<" "<<k2<<endl;
     cout<<max({n*a,(-k1*k1+(1+2*b-2*a)*k1+2*n*a)/2,(-k2*k2+(1+2*b-2*a)*k2+2*n*a)/2})<<endl;
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