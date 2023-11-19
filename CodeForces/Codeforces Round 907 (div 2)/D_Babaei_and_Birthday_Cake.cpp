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

template<class T> struct BIT {
     vector<T> s;
     int n;
     BIT(int n): s(n + 1), n(n) {}
     void update(int i, T v) {
          for (i++; i <= n; i += i & -i) if(s[i]<v) s[i] = v;
     }
     T query(int i) { // EXCLUSIVE interval [0, i)
          T ans = 0;
          for (; i; i -= i & -i) if(s[i]>ans) ans = s[i];
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

const lld pi= 3.14159265358979323846;

void dk(){
     ll n;
     cin>>n; 
     vector<ll>v;
     set<ll>st;
     rep(i,0,n){
          ll r,h;
          cin>>r>>h;
          v.pb(r*r*h);
          st.insert(r*r*h);
     }
     vl vp(st.begin(),st.end());
     BIT<ll>bit(n+1);
     rep(i,0,n){
          ll ind=lower_bound(all(vp),v[i])-vp.begin();
          ll sum=bit.query(ind);
          bit.update(ind,sum+v[i]);
     }
     cout<<fixed<<setprecision(9);
     cout<<(lld)bit.query(n)*pi<<endl;
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