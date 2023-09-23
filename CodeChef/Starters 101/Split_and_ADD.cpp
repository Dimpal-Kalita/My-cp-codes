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


ll calc(ll n){
     __int128 x=n;
     return (x*(x+1)/2)%md;
}

ll recur(ll n, ll l,ll r){
     if(l==1 and r==n) return calc(n);
     if(r<=n/2) return (2*recur(n/2,l,r)-(r-l+1)+md)%md;
     if(l>n/2) return (2*recur(n/2,l-n/2,r-n/2))%md;
     return (((2*recur(n/2,l,n/2))%md-(n/2-l+1)+md)%md + (2*recur(n/2,1,r-n/2))%md)%md;
}

void dk(){
     ll n,l,r;
     cin>>n>>l>>r;
     cout<<recur(n,l,r)%md<<endl;
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