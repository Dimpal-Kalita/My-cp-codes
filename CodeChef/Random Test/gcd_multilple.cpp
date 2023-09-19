	 
	// 2112048
	// Dimpal Kalita
	 
	#include<bits/stdc++.h>
	 
	// #include <ext/pb_ds/detail/standard_policies.hpp>
	 
	using namespace std;
	// using namespace __gnu_pbds;
	 
	 
	#define md                  1000000007
	#define pb                  push_back
	#define endl                "\n"
	#define F                   first
	#define S                   second
	#define inp(v)              for(auto &x: v) cin>>x  
	#define all(x)              (x).begin(), (x).end() 
	#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	 
	 
	typedef long long ll;
	typedef pair<ll,ll> pll;
	typedef pair<int,int>pii;
	typedef unsigned long long ull;
	typedef long double lld;
	// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
	 
	 
	 #define int long long
	 
	
	/*-----------------------------------------------Number theory Starts-----------------------------------------------------------*/
	ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
	ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
	void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
	ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
	ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
	bool revsort(ll a, ll b) {return a > b;}
	ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
	vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
	ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
	ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
	ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
	ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
	ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
	/*-----------------------------------------------Number theory Ends---------------------------------------------------------------*/
	
	
	 
	void dk(){
	  ll n;
	  cin>>n;
	  vector<ll> v(n);
	  inp(v);
	  ll ans=v[0];
	 
	  map<ll, ll> sub_gcd[n];
	 
	  map<ll,ll> mp;
	  mp[v[0]]++;
	 
	  sub_gcd[0][v[0]] = 0;
	  
	  for(int i = 1; i < n; i++)
	  {   
	      sub_gcd[i][v[i]] = 0;
	      map<ll,ll> mp1;
	      mp1[v[i]]=1;
	      ans= (ans*v[i])%md;
	 
	      for(auto it: sub_gcd[i - 1])
	      {
	          ll new_gcd = __gcd(it.first, v[i]);
	          
	          ans=(ans*(expo(new_gcd,mp[it.F],md)))%md;
	 
	          mp1[new_gcd]+=mp[it.F];
	 
	          sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.second + 1);
	      }
	 
	      mp=mp1;
	  }
	 
	  cout<<ans<<endl;
	 
	  return;
	}
	 
	 
	 
	 
	signed main()
	{ 
	    fast_io;
	    int t=1;
	    cin>>t;
	    for(int i=0;i<t;i++){
	    //google(i+1);
	    dk();
	   }
	  return 0;
	}