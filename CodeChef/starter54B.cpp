//2112048
//dimpal kalita
#include<bits/stdc++.h>
using namespace std;


#define md                  1000000007
#define pb                  push_back
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x   
#define all(x)              (x).begin(), (x).end()        
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);




/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 

/*-----------------------------------------------Debug Ends--------------------------------------------------------------------*/


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

ll nCr(ll n, ll r)
{
    // base case
    if (r > n)
        return 0;
 
    // C(n,r) = C(n,n-r) Complexity for
    // this code is lesser for lower n-r
    if (n - r > r)
        r = n - r;
 
    // list to smallest prime factor
    // of each number from 1 to n
    ll SPF[n + 1];
 
    // set smallest prime factor of each
    // number as itself
    for (ll i = 1; i <= n; i++)
        SPF[i] = i;
 
    // set smallest prime factor of all
    // even numbers as 2
    for (ll i = 4; i <= n; i += 2)
        SPF[i] = 2;
 
    for (ll i = 3; i * i < n + 1; i += 2) {
 
        // Check if i is prime
        if (SPF[i] == i) {
            // All multiples of i are
            // composite (and divisible by
            // i) so add i to their prime
            // factorization getpow(j,i)
            // times
            for (ll j = i * i; j < n + 1; j += i)
                if (SPF[j] == j) {
                    SPF[j] = i;
                }
        }
    }
    // Hash Map to store power of
    // each prime in C(n,r)
    map<ll, ll> prime_pow;
 
    // For numerator count frequency of each prime factor
    for (ll i = r + 1; i < n + 1; i++) {
 
        ll t = i;
 
        // Recursive division to find
        // prime factorization of i
        while (t > 1) {
            if (!prime_pow[SPF[t]]) {
                prime_pow[SPF[t]] = 1;
            }
            else
                prime_pow[SPF[t]]++;
            // prime_pow.put(SPF[t],
            // prime_pow.getOrDefault(SPF[t], 0)
            // + 1);
            t /= SPF[t];
        }
    }
 
    // For denominator subtract the power of
    // each prime factor
    for (ll i = 1; i < n - r + 1; i++) {
        ll t = i;
 
        // Recursive division to find
        // prime factorization of i
        while (t > 1) {
            prime_pow[SPF[t]]--;
            // prime_pow.put(SPF[t],
            // prime_pow.get(SPF[t]) - 1);
            t /= SPF[t];
        }
    }
 
    // long because mod is large and a%mod
    // * b%mod can overflow int
     ll ans = 1, mod = 1000000007;
 
    // use (a*b)%mod = (a%mod * b%mod)%mod
    for (auto it : prime_pow)
 
        // pow(base,exp,mod) is used to
        // find (base^exp)%mod fast
        ans = (ans
               * expo(it.first, prime_pow[it.first], mod))
              % mod;
    return ans;
}
void dk(){
   ll n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   ll x= nCr(n,k)%md;
   ll ans= expo(2, x, md)%md;

   cout<< ans<<endl; 

   return;
}



int main()
{ 
    fast_io;
    #ifndef ONLINE_JUDGE
    file_io;
    freopen("D:/cp/error.txt", "w+", stderr);
    #endif
    //USACO
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
    }
return 0;
}