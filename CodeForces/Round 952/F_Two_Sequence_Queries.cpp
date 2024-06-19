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

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


template<class T, T (*e)(), T (*op)(T, T), class F, F (*id)(),
     T (*onto)(F, T), F (*comp)(F, F)>
struct lazy_segtree {
     int N, log, S;
     vector<T> d;
     vector<F> lz;
     lazy_segtree(const vector<T>& v):
          N(sz(v)), log(__lg(2 * N - 1)), S(1 << log), d(2 * S, e()),
          lz(S, id()) {
          for (int i = 0; i < N; i++) d[S + i] = v[i];
          for (int i = S - 1; i >= 1; i--) pull(i);
     }
     void apply(int k, F f) {
          d[k] = onto(f, d[k]);
          if (k < S) lz[k] = comp(f, lz[k]);
     }
     void push(int k) {
          apply(2 * k, lz[k]), apply(2 * k + 1, lz[k]), lz[k] = id();
     }
     void push(int l, int r) {
          int zl = __builtin_ctz(l), zr = __builtin_ctz(r);
          for (int i = log; i > min(zl, zr); i--) {
               if (i > zl) push(l >> i);
               if (i > zr) push((r - 1) >> i);
          }
     }
     void pull(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
     void set(int p, T x) {
          p += S;
          for (int i = log; i >= 1; i--) push(p >> i);
          for (d[p] = x; p /= 2;) pull(p);
     }
     T query(int l, int r) {
          if (l == r) return T{};
          push(l += S, r += S);
          T vl = e(), vr = e();
          for (; l < r; l /= 2, r /= 2) {
               if (l & 1) vl = op(vl, d[l++]);
               if (r & 1) vr = op(d[--r], vr);
          }
          return op(vl, vr);
     }
     void update(int l, int r, F f) {
          if (l == r) return;
          push(l += S, r += S);
          for (int a = l, b = r; a < b; a /= 2, b /= 2) {
               if (a & 1) apply(a++, f);
               if (b & 1) apply(--b, f);
          }
          int zl = __builtin_ctz(l), zr = __builtin_ctz(r);
          for (int i = min(zl, zr) + 1; i <= log; i++) {
               if (i > zl) pull(l >> i);
               if (i > zr) pull((r - 1) >> i);
          }
     }
};

ll e() { return 0; }
ll op(ll a, ll b) { return (a + b)%md; }
ll onto(ll f, ll x) { return (f + x)%md; }
ll id() { return 0; }
ll comp(ll f, ll g) { return (f + g)%md; }


void dk(){
     ll n,q;
     cin>>n>>q;
     vl a(n),b(n);
     inp(a);
     inp(b);
     vl c(n);
     for(int i=0;i<n;i++){
          c[i]=(a[i]*b[i])%md;
     }
     lazy_segtree<ll, e, op, ll, id, onto, comp> A(a),B(b),C(c);
     while(q--){
          int t;
          cin>>t;
          if(t==1){
               int l,r,x;
               cin>>l>>r>>x;
               l--;
               A.update(l,r,x);
               ll sum=B.query(l,r);
               sum=(sum*x)%md;
               C.update(l,r,sum);
          }
          else if(t==2){
               int l,r,x;
               cin>>l>>r>>x;
               l--;
               B.update(l,r,x);
               ll sum=A.query(l,r);
               sum=(sum*x)%md;
               C.update(l,r,sum);
          }else{
               int l,r;
               cin>>l>>r;
               l--;
               // cout<<C.query(l,r)<<endl;
          }
     }
     rep(i,0,n){
          cout<<A.query(i,i+1)<<" ";
     }
     cout<<endl;
     rep(i,0,n){
          cout<<B.query(i,i+1)<<" ";
     }
     cout<<endl;
     rep(i,0,n){
          cout<<C.query(i,i+1)<<" ";
     }
     cout<<endl;
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