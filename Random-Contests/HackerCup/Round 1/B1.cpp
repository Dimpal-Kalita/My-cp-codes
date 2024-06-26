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




vl prime=sieve(1e6);

void dk(){
     ll n;
     cin>>n;

     ll N=n;
     vl v; 
     for(auto i:prime){
          if(i*i>n) break;
          while(n%i==0){
               n/=i;
               v.pb(i);
          }
     }
     if(n>1){
          v.pb(n);
     }
     ll sum=accumulate(all(v),0ll);
     if(sum>41){
          cout<<"-1"<<endl;
          return;
     }
     vl vp=v;
     ll extra=41-sum;
     while(sum<41){
          sum++;
          v.pb(1);
     }
     // cout<<v.size()<<" ";
     // for(auto i:v){
     //      cout<<i<<" ";
     // }
     // cout<<endl;

     while(1){
          bool flag=0;
          sort(all(vp),greater<ll>());
          ll xx=-1,yy=-1;
          for(int i=0;i<sz(vp);i++){
               for(int j=0;j<sz(vp);j++){
                    if(i==j) continue;
                    ll x=vp[i];
                    ll y=vp[j];
                    ll val= x*y-x-y;
                    if(val<=extra){
                         extra-=val;
                         vp.push_back(x*y);
                         xx=i;
                         yy=j;
                         flag=1;
                         break;
                    }
               }
               if(flag) break;
          }
          if(flag){
               vl tt;
               for(int i=0;i<sz(vp);i++){
                    if(i==xx ||i==yy) continue;
                    tt.pb(vp[i]);
               }
               vp=tt;
          }
          if(!flag) break;
     }
     while(extra){
          extra--;
          vp.push_back(1);
     }
     cout<<vp.size()<<" ";
     for(auto i:vp){
          cout<<i<<" ";
     }
     cout<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
      cout<<"Case #"<<i+1<<": ";
      dk();
   }
  return 0;
}