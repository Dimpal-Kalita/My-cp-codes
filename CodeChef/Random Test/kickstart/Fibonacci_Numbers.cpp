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
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);
#define int                 long long

using pii = pair<int,int>;
using ull = unsigned long long;
using ll = long long;
using lld = long double;
using vi  = vector<int>;


template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) a.d[i][j] = (a.d[i][j]+
            (d[i][k] * m.d[k][j])%md)%md;
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i, 0, N) rep(j, 0, N) ret[i] = (ret[i]+(d[i][j] * vec[j])%md)%md;
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i, 0, N) a.d[i][i] = 1;
        while (p) {
            if (p & 1) a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};


void dk(){
    int n;
    cin>>n;
    Matrix<int,2> base={1,0,0,1};
    Matrix<int,2> m={1,1,1,0};

    for(;n>0; n/=2,m=m*m){
        if(n&1) base= base*m;
    }
    cout<<base.d[0][1]<<endl;
}



#undef int
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