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
//const int N = 100;
// initialise nCr struct
// nCr comb(N , mod);



template<class T>
pair<vector<bool>, vector<T>> dijkstra(
     const vector<vector<pair<int, T>>>& adj, int s) {
     using ST = pair<T, int>;
     priority_queue<ST, vector<ST>, greater<ST>> q;
     vector<T> dist(adj.size());
     vector<bool> seen(adj.size());
     q.emplace(T{}, s);
     seen[s] = 1;
     while (!q.empty()) {
          auto [d, u] = q.top();
          q.pop();
          if (dist[u] < d) continue;
          for (auto [v, w] : adj[u])
               if (!seen[v] || d + w < dist[v]) {
                    q.emplace(dist[v] = d + w, v);
                    seen[v] = 1;
               }
     }
     return {seen, dist};
}

void dk(){
     ll n,m;
     cin>>n>>m;
     vector<pll>vp(n);
     for(auto &it:vp) cin>>it.F; 
     for(auto &it:vp) cin>>it.S;
     vector<vector<pair<int,ll>>>adj1(n+1),adj2(n+1);
     rep(i,0,m){
          ll x,y,w;
          cin>>x>>y>>w;
          adj1[x].pb({y,w});
          adj1[y].pb({x,w});
     }
     rep(i,0,m){
          ll x,y,w;
          cin>>x>>y>>w;
          adj2[x].pb({y,w});
          adj2[y].pb({x,w});
     }
     int x,y;
     cin>>x>>y;
     auto [seen1, dist1] = dijkstra(adj1, x);
     auto [seen2, dist2] = dijkstra(adj2, y);
     ll ans=LLONG_MAX;
     rep(i,1,n+1){
          for(int j=1;j*j<=i;j++){
               if(i%j==0){
                    if(seen1[j] && seen2[i]){
                         ans=min(ans,dist1[j]+dist2[i]+vp[j-1].F*vp[i-1].S);
                    }
                    if(seen1[i/j] && seen2[i]){
                         ans=min(ans,dist1[i/j]+dist2[i]+vp[(i/j)-1].F*vp[i-1].S);
                    }
               }
          }
     }
     cout<<(ans==LLONG_MAX?-1:ans)<<endl;
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