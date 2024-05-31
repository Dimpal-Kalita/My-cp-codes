#include<bits/stdc++.h>
using namespace std;

#define md                  998244353
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



/*-----------------------------------------------Number theory Starts-----------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*-----------------------------------------------Number theory Ends---------------------------------------------------------------*/

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


const ll N=20,M=1002;


void dk(){
     ll n;
     cin>>n;
     vector<mi> v(n);
     inp(v);
     sort(all(v));
     vector<mi> times(N+1,0);
     mi ans=0;
     times[0]=mi(1);
     for(ll i=0;i<n;i++){
          for(ll j=0;j<N;j++){
               if(j<=v[i].v) ans+=(v[i]*times[j]);
               else ans+=(j+1)/2;
          }
          for(ll j=v[i].v;j<N;j++){
               times[j]+=times[j-v[i].v];
          }
          cout<<v[i].v<<" "<<ans<<endl;
     }
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