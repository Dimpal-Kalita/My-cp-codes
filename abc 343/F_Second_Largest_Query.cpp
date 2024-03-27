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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
     tree_order_statistics_node_update>;

struct SegTree {
     typedef struct{
          ll mx;
          ll smx;
     } T;
     static constexpr T unit = {0,0};
     T f(T a, T b) {
          if(a.mx==b.mx) return {a.mx,max(a.smx,b.smx)};
          if(a.mx>b.mx) return {a.mx,max(a.smx,b.mx)};
          return {b.mx,max(a.mx,b.smx)};
     } 
     vector<T> s;
     int n;
     SegTree(int n = 0, T def = unit): s(2 * n, def), n(n) {}
     void update(int pos, T val) {
          for (s[pos += n] = val; pos /= 2;)
               s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
     }
     T query(int b, int e) { // query [b, e)
          T ra = unit, rb = unit;
          for (b += n, e += n; b < e; b /= 2, e /= 2) {
               if (b % 2) ra = f(ra, s[b++]);
               if (e % 2) rb = f(s[--e], rb);
          }
          return f(ra, rb);
     }
};

void dk(){
     ll n,q;
     cin>>n>>q;
     vl v(n+1);
     rep(i,1,n+1) cin>>v[i];
     map<ll,Tree<ll>> mp;
     SegTree st(n+1);
     rep(i,1,n+1){
          mp[v[i]].insert(i);
          st.update(i,{v[i],0});
     }
     while(q--){
         ll t;
         cin>>t;
         if(t==1){
          ll ind,x;
          cin>>ind>>x;
          mp[v[ind]].erase(ind);
          mp[x].insert(ind);
          v[ind]=x;
          st.update(ind,{x,0});
         }else{
               ll l,r;
               cin>>l>>r;
               ll x=st.query(l,r+1).smx;
               ll ans=mp[x].order_of_key(r+1)-mp[x].order_of_key(l);
               cout<<ans<<endl;
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