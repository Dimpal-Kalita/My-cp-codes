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

bool check(ll n, ll k){
    ll x=0;
    for(ll i=1;i<n;i++){
        ll sq=sqrt(n*n-i*i);
        x+=sq;
    }
    x*=4;
    x+= 4*n+1;
    return x>=k;
}
void dk(){
    ll n;
    cin>>n;
    ll l=0,r=sqrt(n)+1,ans=0;
    while(l<r){
        ll mid=(l+r)/2;
        if(check(mid,n)){
            r=mid;
        }else l=mid+1;
    }
    cout<<r<<endl;

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
