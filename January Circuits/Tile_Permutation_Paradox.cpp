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


struct nCr{
    ll maxx , mod; 
    vector<ll> fact, ifact; 
    inline ll mul(ll a, ll b) { return a *1LL* b % mod ;}
    ll power(ll a, ll n) {
        if(n == 0) return 1 ; 
        int p = power(a, n/2) % mod ; 
        p = mul(p, p) ;  
        return n & 1 ? mul(p, a) : p ; 
    }
    int invMod(int a) {return power(a,mod-2);}
    void pre() {
        fact[0] = 1 ;
        for(int i = 1;i< maxx;++i) fact[i] = mul(i, fact[i-1]) ;
        ifact[maxx-1] = invMod(fact[maxx-1]) ; 
        for(int i = maxx-1 ; i>0 ;--i) ifact[i-1] = mul(ifact[i], i) ;
    }
    nCr(int _mxN, int _M) {
        maxx = _mxN + 1; 
        mod = _M ; 
        fact.resize(maxx) ; 
        ifact.resize(maxx) ;
        pre() ;  
    }
    ll C(ll n, ll r) {
        if (n < r || r < 0 || n < 0) return 0;
        return mul(fact[n], mul(ifact[r], ifact[n-r])) ;
    }
};
//maxx N we need
const int N = 10002;
// initialise nCr struct
nCr comb(N , md);




void dk(){
     ll n,m;
     cin>>n>>m;

     ll ans=0;
     rep(i,0,n){
         if(m*i>n) break;
         ll x=n-m*i+1;
         ans=(ans+comb.C(x+i-1,i))%md;
         ans=(ans+md-1)%md;
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