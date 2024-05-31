/**
 * 
 * author: Dimpal Kalita
 * date: 24/03/2024 16:07:26
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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



template<int MOD, int RT> struct mint {
  using mr = const mint&;
  int v;
  explicit operator int() const {
    return v;
  } // explicit -> don't silently convert to int
  mint(ll _v = 0) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  mint& operator+=(mr o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(mr o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(mr o) {
    v = int(ll(v) * o.v % MOD);
    return *this;
  }
  mint& operator/=(mr o) { return (*this) *= inv(o); }
  friend mint pow(mint a, ll p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mint inv(mr a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  friend mint operator+(mint a, mr b) { return a += b; }
  friend mint operator-(mint a, mr b) { return a -= b; }
  friend mint operator*(mint a, mr b) { return a *= b; }
  friend mint operator/(mint a, mr b) { return a /= b; }
  bool operator==(mr o) const { return v == o.v; }
  friend bool operator!=(mr a, mr b) { return !(a == b); }
  friend bool operator<(mr a, mr b) { return a.v < b.v; }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend istream& operator>>(istream& is, mint& a) {
    return is >> a.v;
  }
  friend ostream& operator<<(ostream& os, const mint& a) {
    return os << a.v;
  }
  static constexpr mint rt() {
    return RT;
  } // primitive root for FFT
};
using mi =
  mint<md, 5>; // 5 is primitive root for both common mods


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
const int N = 3e5;
// initialise nCr struct
nCr comb(N , md);


bool check(vl a, vl b, ll n){
  if(a.front()!=b.front()) return 0;
  vl temp(n+1,0);
  ll x=n;
  for(auto i:a){
    temp[i]=x--;
  }
  for(auto i:b){
    if(i==a.front()) continue;
    temp[i]=x--;
  }
  // debug(temp);
  vl ps;
  ll last=-1;
  for(int i=1;i<=n;i++){
    if(temp[i]>last) ps.pb(i);
    last=max(last,temp[i]);
  }
  // debug(ps);
  reverse(all(ps));
  if(ps!=a) return 0;
  vl ss;
  last=-1;
  for(int i=n;i>=1;i--){
    if(temp[i]>last) ss.pb(i);
    last=max(last,temp[i]);
  }
  reverse(all(ss));
  // debug(ss);
  if(ss!=b) return 0;
  return 1;
}

void dk(){      
  ll n,m1,m2;
  cin>>n>>m1>>m2;
  vl a(m1),b(m2);
  inp(a);
  inp(b);
  reverse(all(a));
  if(!check(a,b,n)){
    cout<<0<<endl;
    return;
  }
  mi ans=comb.C(n-1,a.front()-1);
  ll mx=a.front()-1;
  rep(i,1,sz(a)){
    ll r=a[i-1]-a[i]-1;
    mx--;
    // cout<<mx<<" "<<r<<endl;
    ans*=comb.C(mx,r);
    ans*=comb.fact[r];
    mx-=r;
  }
  mx=n-b.front();
  rep(i,1,sz(b)){
    ll r=b[i]-b[i-1]-1;
    mx--;
    // cout<<mx<<" "<<r<<endl;
    ans*=comb.C(mx,r);
    ans*=comb.fact[r];
    mx-=r;
  }
  cout<<ans<<endl;
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