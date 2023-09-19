// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (ll i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using pii = pair<int,int>;
using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using vi  = vector<int>;




template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i, 0, N) rep(j, 0, N) rep(k, 0, N){
           T x =(d[i][k] * m.d[k][j])%md;
           a.d[i][j]= (a.d[i][j]+x)%md;
        }
        return a;
    }

    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i, 0, N) rep(j, 0, N){
            T x= (d[i][j]*vec[j])%md;
            ret[i]= (ret[i]+x)%md;
        }
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i, 0, N) a.d[i][i] = 1ll;
        while (p) {
            if (p & 1) a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};


void dk(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];
    Matrix<ll,110> base, m;

    rep(i,0,n) rep(j,0,n) if(__builtin_popcount((v[i]^v[j]))%3==0) base.d[i][j]=1ll;
        
    base= (base^(k-1));
    ll ans=0;
    rep(i,0,n) rep(j,0,n) ans= (ans+base.d[i][j])%md;
    cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}