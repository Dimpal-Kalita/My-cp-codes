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
using LL  = __int128;



template<typename T>
T binpow(T a, T b) {
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a;
        }
        a = 1LL * a * a;
        b >>= 1;
    }
    return ans;
}


LL check(ll k,ll x,ll n){
    LL val=0;
    LL K=k;
    for(LL i=0;i<=x;i++){
        val+= binpow(K,i);
        if(val>n) return val;
    }
    return val;
}



void dk(){
    ll n;
    cin>>n;
    
    for(ll x=2;x<60;x++){

        ll l=2,r=1e9;
        while(l<=r){
            ll mid= l+(r-l)/2;
            LL val= check(mid,x,n);
            if(val==n){
                cout<<"YES"<<endl;
                return;
            }
            if(val>n){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    cout<<"NO"<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}


