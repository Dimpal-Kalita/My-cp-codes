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


struct Tree {
     typedef struct Node{
          ll mx;
          ll sum;
     } T;
     static constexpr T unit = {0,0};
     T f(T a, T b) {
          ll nmx=max(a.mx+b.sum,b.mx);
          ll nsum=a.sum+b.sum;
          return {nmx,nsum};
     } // (any associative fn)
     vector<T> s;
     int n;
     Tree(int n = 0, T def = unit): s(2 * n, def), n(n) {}
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
      vl a(n),b(n);
      inp(a);
      inp(b);
      Tree t(n+1);
      vl c(n-1);
      inp(c);
      ll sum=0;
      rep(i,0,n){
          sum+=a[i];
          t.update(i,{max(0LL,a[i]-b[i]),a[i]-b[i]});
      }
      while(q--){
          ll ind,x,y,z;
          cin>>ind>>x>>y>>z;
          ind--;
          sum-=a[ind];
          a[ind]=x;
          b[ind]=y;
          sum+=a[ind];
          t.update(ind,{max(0LL,x-y),x-y});
          cout<<sum-t.query(0,n).mx<<endl;
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