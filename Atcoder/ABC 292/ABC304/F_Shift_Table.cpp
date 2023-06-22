/**
 * 
 * author: Dimpal Kalita
* 
 */

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
ll expo(ll a, ll b, ll mod=md) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m=md) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m=md) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m=md) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m=md) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*-----------------------------------------------Number theory Ends---------------------------------------------------------------*/







const int N=1e6;
vector<ll> spf(N);
void dk(){
     ll n;
     cin >> n;
    string s;
    cin >> s;
    vl todo;
    for(int i = 0 ; i < n ; i ++){
        if(s[i] == '.') todo.pb(i+1);
    }
    map<ll,ll> vis;
    vl div;
    for(int i= 2;i*i<=n;i++){
        if(n%i == 0){
            div.pb(i);
            vis[i] = 1;
            if(i*i != n){
                div.pb(n/i);
                vis[n/i] = 1;
            } 
        }
    }
    sort(all(div));
    reverse(all(div));
    ll ans = 0;
    for(int i = 0 ; i < sz(div) ; i ++){
        if(vis.count(div[i])){
            ll x = div[i];
            while(x > 1){
                vis.erase(spf[x]);
                vis.erase(x);
                x/=spf[x];
            }
            set<ll>st;
            for(auto it1: todo){
                st.insert(it1%div[i]);
            }
            ll m = div[i]-st.size();
            ans = mod_add(ans,expo(2 , m));
            ans = mod_sub(ans,1);
        }
    }
    ans = mod_add(ans,1);
    cout<<ans<<endl;      

}



int main()
{ 
     fast_io;
     for (int i = 0; i <N; i++) {
          spf[i] = 1;
     }
     for(int i = 2 ; i < N ; i++){
          if(spf[i] == 1){
               spf[i] = i;
               for(int j = 2*i ; j <N; j += i){
                    if(spf[j] == 1) spf[j] = i;
               }
          }
     } 
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}