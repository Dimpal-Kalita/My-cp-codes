#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// linear sieve
vi ps, pf;
void sieve(int mx) {
  pf = vi(mx+1);
  rep(i,mx+1) pf[i] = i;
  for (int i = 2; i <= mx; ++i) {
    if (pf[i] == i) ps.pb(i);
    for (int j = 0; j < sz(ps) && ps[j] <= pf[i]; ++j) {
      int x = ps[j]*i;
      if (x > mx) break;
      pf[x] = ps[j];
    }
  }
}
inline bool isp(int x) { return pf[x] == x && x >= 2;}
vp factor(int x) { // asc
  if (x == 1) return {};
  vp res(1, P(pf[x], 0));
  while (x != 1) {
    if (res.back().fi == pf[x]) res.back().se++;
    else res.pb(P(pf[x],1));
    x /= pf[x];
  }
  return res;
}
//

struct Solver {
  void solve() {
    sieve(50);
    int n;
    scanf("%d",&n);
    vi a(n);
    cin>>a;
    ll ans = LINF;
    int m = sz(ps);
    int m2 = 1<<m;
    rep(i,m2) {
      ll x = 1;
      rep(j,m) if (i>>j&1) x *= ps[j];
      bool ok = true;
      rep(j,n) if (__gcd((int)x,a[j]) == 1) ok = false;
      if (ok) mins(ans, x);
    }
    cout<<ans<<endl;
  }
};

int main() {
  int ts = 1;
  // scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}
