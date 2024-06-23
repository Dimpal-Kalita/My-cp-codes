#include<bits/stdc++.h>
using namespace std;

#define md                  998244353
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


ll mul(ll a, ll b, ll m) {        
     b%=(m-1);
     a%=(m-1);
     return a*b%(m-1);
}

void dk(){
      ll n;
      cin>>n;
      string s=to_string(n);
      ll l=sz(s);
      mi x=n;
      ll y=mul(n,l,md);
      mi top=pow(mi(10),y);
      top-=mi(1);
      ll z=mul(l,1LL,md);
      mi d=pow(mi(10),z);
      d-=mi(1);
      mi ans=top/d;
      ans=(ans*x);
      cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   