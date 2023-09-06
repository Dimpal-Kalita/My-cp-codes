#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
typedef long long ll;
typedef unsigned long long ul;
constexpr ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a / gcd(a, b) * b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll modpow(ll x, ll y, ll p) {ll res = 1; x = x % p; if (x == 0) return 0; while (y > 0) {if (y & 1)res = (res * x) % p; y = y >> 1; x = (x * x) % p;} return res;}
ll power(ll a, ll b) {if (b == 0) {return 1;} if (b % 2 == 0) {ll t = power(a, b / 2); return t * t;} else {ll t = power(a, (b - 1) / 2); t = t * t; return a * t;}}
ll power2(ll a, ll b, ll m) {if (b == 0) {return 1;} if (b % 2 == 0) {ll t = power2(a, b / 2, m); return t * t % m;} else {ll t = power2(a, (b - 1) / 2, m); t = (t * t) % m; return a * t % m;}}
ll inverse(ll a, ll m) {return power2(a, m - 2, m);}
ll introot(ll x) {ll ans = sqrtl(x) + 2; while (ans * ans > x) ans--; return ans;}
bool ispowerof2(ll n) {return (n != 0) && (!(n & (n - 1)));}
bool isprime(ll n) {if (!(n & 1) && n > 2)return false; for (ll i = 3; i * i <= n; i += 2) {if (n % i == 0)return false;} return true;}


void solve()
{
   int n, k, x;
   cin >> n >> k >> x;
   if (k == 1)
   {
      cout << "NO\n";
      return;
   }
   if(x!=1)
   {
      cout << "YES\n"<<n<<'\n';
      for(int i=0;i<n;i++) cout<<"1 ";
      return;
   }
   if (k == 2 && x == 1 && n % 2 == 1)
   {
      cout << "NO\n";
      return;
   }
   if(n%2==0)
   {
      cout << "YES\n"<<n/2<<'\n';
      for(int i=0;i<n/2;i++) cout<<"2 ";
      return;
   }
   int y=n/2;
   cout << "YES\n"<<y<<'\n'<<"3 ";
   for(int i=0;i<y-1;i++) cout<<"2 ";

}

int main()
{


   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   // cout.tie(NULL);
   ll t = 1;
   cin >> t;
   while (t--)
   {
      solve();
   }

}