#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define f                   first
#define s                   second
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


template<class t> struct bit {
     vector<t> s;
     int n;
     bit(int n): s(n + 1), n(n) {}
     void update(int i, t v) {
          for (i++; i <= n; i += i & -i) s[i] += v;
     }
     t query(int i) { // exclusive interval [0, i)
          t ans = 0;
          for (; i; i -= i & -i) ans += s[i];
          return ans;
     } // inclusive-exclusive interval [l, r)
     t query(int l, int r) { return query(r) - query(l); }
     int kth(t k) { // 0-indexed, returns n if k > sum of tree
          if (k < 0) return -1;
          int i = 0;
          for (int pw = 1 << __lg(n); pw; pw >>= 1)
               if (i + pw <= n && s[i + pw] <= k) k -= s[i += pw];
          return i;
     }
};

void dk(){
     ll n,q;
     cin>>n>>q;
     vl a;
     vector<pll>v;
     rep(i,0,n){
          ll x;
          cin>>x;
          a.pb(x);
          v.pb({x,i});
     }
     vector<array<ll,3>>query;
     rep(i,0,q){
          ll l,r;
          cin>>l>>r;
          query.pb({a[r],l,i});
     }

     sort(all(v),greater<pll>());
     sort(all(query),greater<array<ll,3>>());
     bit<ll>bit(n+1);
     vector<ll>ans(q);

     for(int i=0,j=0;i<q;i++){ 
          ll l=query[i][1],val=query[i][0],ind=query[i][2];
          while(j<n and v[j].first>val){
               bit.update(v[j].second,v[j].first);
               j++;
          }
          ans[ind]=bit.query(l+1);
     }
     for(auto i:ans){
          cout<<i<<" "; 
     }
     cout<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   