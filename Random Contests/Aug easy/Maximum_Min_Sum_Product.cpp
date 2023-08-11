/**
 * 
 * author: Dimpal Kalita
 * date: 05/08/2023 10:50:56
 * 
 */

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


struct Tree {
     typedef int T;
     static constexpr T unit = INT_MAX;
     T f(T a, T b) { return min(a, b); } // (any associative fn)
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
      ll n;
      cin>>n;
      vl v(n);
      inp(v);
      vector<ll>ps(n+1,0);
      for(int i=0;i<n;i++){
        ps[i+1]=ps[i]+v[i];
      }
      ll ans=-1e18;
      for(int i=0;i<n;i++){
          ll mn=1e18;
          for(int j=i;j<n;j++){
               mn=min(mn,v[j]);
               ll res=mn*(ps[j+1]-ps[i]);
               ans=max(ans,res);
          }
      }
      cout<<(ans+md)%md<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}