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



ll n,m;
vl a,b;

bool check(ll mid){
    ll x= m*mid;
    for(auto it:a){
        if(x>it) return 0;
    }
    ll val=n*mid;
    for(auto it:b){
        if(val>it) return 0;
    }
    return 1;
}

void dk(){
    cin>>n>>m;
    a.resize(n);
    b.resize(m);
    inp(a);
    inp(b);
    ll l=0,r=1e12,ans=0;
    //check(100);
    while(l<r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid;
    }
    cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    //cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}
