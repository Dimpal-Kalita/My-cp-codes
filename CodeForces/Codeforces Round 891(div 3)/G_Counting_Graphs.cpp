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


const ll mod = 998244353;
ll modpow(ll b, ll e) {
     ll ans = 1;
     for (; e; b = b * b % mod, e /= 2)
          if (e & 1) ans = ans * b % mod;
     return ans;
}

struct DSU {
     vector<ll> s;
     DSU(int n): s(n, -1) {}
     ll find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
     bool join(int a, int b) {
          a = find(a), b = find(b);
          if (a == b) return false;
          if (s[a] > s[b]) swap(a, b);
          s[a] += s[b], s[b] = a;
          return true;
     }
     ll size(int i) { return -s[find(i)]; }
     bool same(int a, int b) { return find(a) == find(b); }
};

void dk(){
     ll n,s;
     cin>>n>>s;
     vector<array<ll,3>>v; 
     rep(i,0,n-1){
          ll x,y,w;
          cin>>x>>y>>w;
          v.pb({w,x,y});
     }
     sort(all(v));
     ll ans=1;
     DSU dsu(n+1);
     for(auto [w,u,v]:v){
          ans=(ans*modpow(s-w+1,dsu.size(u)*dsu.size(v)-1))%mod;
          dsu.join(u,v);
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