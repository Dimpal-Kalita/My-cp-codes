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


ll n,m;
string s,t;


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

vi pi(const string& s) {
     vi p(sz(s));
     rep(i, 1, sz(s)) {
          int g = p[i - 1];
          while (g && s[i] != s[g]) g = p[g - 1];
          p[i] = g + (s[i] == s[g]);
     }
     return p;
}
vi match(const string& s, const string& pat) {
     vi p = pi(pat + '\0' + s), res;
     rep(i, sz(p) - sz(s), sz(p)) if (p[i] == sz(pat))
          res.push_back(i - 2 * sz(pat));
     return res;
}

void dk(){
     ll q;
     cin>>n>>m>>q;
     cin>>s>>t;
     BIT<int> ps(n+m+1),ss(n+m+1);
     vi v=match(s,t);
     for(auto i:v){
          ps.update(i,1);
          i+=sz(t)-1;
          ss.update(i,1);
     }
     while(q--){
          ll l,r;
          cin>>l>>r;
          l--,r--;
          if(t.length()>r-l+1){
               cout<<0<<endl;
               continue;
          }
          ll ans=0;
          ans+=ps.query(l,r+1);
          ans-=ss.query(r+1,r+sz(t));
          cout<<ans<<endl;
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