/**
 * 
 * author: Dimpal Kalita
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
     static constexpr T unit = 0;
     T f(T a, T b,int ct) { return (ct%2?(a^b):(a|b)); }
     vector<T> s;
     int n;
     Tree(int n = 0, T def = unit): s(2 * n, def), n(n) {}
     void update(int pos, T val) {
          int ct=0;
          for (s[pos += n] = val; pos /= 2;ct++)
               s[pos] = f(s[pos * 2], s[pos * 2 + 1],ct);
     }
};

void dk(){
     int n,q;
     cin>>n>>q;
     Tree t(1<<n);
     rep(i,0,1<<n){
          int x;
          cin>>x;
          t.update(i,x);
     }
     while(q--){
          int p,b;
          cin>>p>>b;
          p--;
          t.update(p,b);
          cout<<t.s[1]<<endl;
     }
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}