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





/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(stack<T> v){cerr<< "[" ; while(!v.empty()){_print(v.top()); cerr<< " " ; v.pop();} cerr<< "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for(auto i: v){_print(i);cerr << " " ;} cerr<< "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------------Debug Ends--------------------------------------------------------------------*/





// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
struct H {
     ull x;
     H(ull x = 0): x(x) {}
     H operator+(H o) { return x + o.x + (x + o.x < x); }
     H operator-(H o) { return *this + ~o.x; }
     H operator*(H o) {
          auto m = (__uint128_t)x * o.x;
          return H((ull)m) + (ull)(m >> 64);
     }
     H operator+=(H o) { return *this = *this + o; }
     H operator-=(H o) { return *this = *this - o; }
     H operator*=(H o) { return *this = *this * o; }
     ull get() const { return x + !~x; }
     bool operator==(H o) const { return get() == o.get(); }
     bool operator<(H o) const { return get() < o.get(); }
};
static const H C =
     (ll)1e11 + 3; // (order ~ 3e9; random also ok)
struct HashInterval {
     vector<H> ha, pw;
     HashInterval(string& str): ha(sz(str) + 1), pw(ha) {
          pw[0] = 1;
          rep(i, 0, sz(str)) ha[i + 1] = ha[i] * C + str[i],
                                                                           pw[i + 1] = pw[i] * C;
     }
     H hashInterval(int a, int b) { // hash [a, b)
          return ha[b] - ha[a] * pw[b - a];
     }
};
vector<H> getHashes(string& str, int length) {
     if (sz(str) < length) return {};
     H h = 0, pw = 1;
     rep(i, 0, length) h = h * C + str[i], pw = pw * C;
     vector<H> ret = {h};
     rep(i, length, sz(str)) {
          ret.push_back(h = h * C + str[i] - pw * str[i - length]);
     }
     return ret;
}
H hashString(string& s) {
     H h{};
     for (char c : s) h = h * C + c;
     return h;
}

template<class T> struct BIT {
     vector<T> s;
     int n;
     BIT(int n): s(n + 1), n(n) {}
     void update(int i, T v) {
          for (i++; i <= n; i += i & -i) s[i] += v;
     }
     T query(int i) { // EXCLUSIVE interval [0, i)
          T ans = 0;
          for (; i; i -= i & -i) ans += s[i];
          return ans;
     } // INCLUSIVE-EXCLUSIVE interval [l, r)
     T query(int l, int r) { return query(r) - query(l); }
     int kth(T k) { // 0-indexed, returns n if k > sum of tree
          if (k < 0) return -1;
          int i = 0;
          for (int pw = 1 << __lg(n); pw; pw >>= 1)
               if (i + pw <= n && s[i + pw] <= k) k -= s[i += pw];
          return i;
     }
};

void dk(){
      ll n,m;
      cin>>n>>m;
      BIT<H>bit(n),bitrev(n);
      string s,rev;
      cin>>s;
      while(m--){
          ll t;
          cin>>t;
          if(t==1){
               ll l;
               char c;
               cin>>l>>c;
               l--;
          }else{
               ll l,r;
               cin>>l>>r;
               l--;
               cout<<bit.query(l,r).x<<" "<<bitrev.query(n-r,n-l).x<<endl;
               if(bit.query(l,r)==bitrev.query(n-r,n-l)){
                    cout<<"Yes"<<endl;
               }else{
                    cout<<"No"<<endl;
               }
          }
      }
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