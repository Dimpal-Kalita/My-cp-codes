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
          for (i++; i <= n; i += i & -i) s[i] += v;
     }
     void update(int l, int r, T v) { // INCLUSIVE interval [l, r]
          update(l, v);
          update(r + 1, -v);
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
     vl v(n);
     inp(v);
     BIT <ll> b(n+2);
     for(int i=0;i<n;i++){
          b.update(i,v[i]);
     }
     for(int i=0;i<1;i++){
          ll x;
          cin>>x;
          ll cur=b.query(x,x+1);
          v[i]-=x;
          ll every= cur/n;
          ll rem=cur%n;
          b.update(0,n+1,every);
          if(x<n-1){
               ll right= min(x+rem+1,n);
               b.update(x+1,right,right-(x+1));
               rem-=(right-x-1);
               // cout<<right<<" "<<right-x<<endl;
          }
          if(rem>0){
               b.update(0,rem,rem);
               // b.update(rem,-1);
          }
          // cerr<<cur<<" "<<rem<<" ";
     }
     rep(i,0,n){
          cout<<v[i]+b.query(i)<<" ";
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