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
const int N = 1e3+2;
// initialise nCr struct
nCr comb(N , md);


vector<vl>dp;
ll k;
vl v(26);
ll recur(ll ind,ll cnt){
     if(ind==26){
          if(cnt==0) return 1;
          return 0;
     }
     if(dp[ind][cnt]!=-1) return dp[ind][cnt];
     ll ans=recur(ind+1,cnt);
     for(int i=1;i<=min(v[ind],cnt);i++){
          ans+=(comb.ifact[i]*recur(ind+1,cnt-i)%md);
          ans=ans%md;
     }
     return dp[ind][cnt]=ans;
}



void dk(){
      cin>>k;
      inp(v);
      dp.assign(26,vl(N,-1));
      ll ans=0;
      for(int i=k;i>=1;i--){
          ans=(ans+(recur(0,i)*comb.fact[i])%md)%md;
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