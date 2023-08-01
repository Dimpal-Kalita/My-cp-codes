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

struct node{
     int mn, g,count;
};

struct Tree {
     typedef node T;
     static constexpr T unit = {INT_MAX,0,1};
     T f(T a, T b) { 
          int count=0;
          int mn=min(a.mn,b.mn);
          if(a.mn==mn) count+=a.count;
          if(b.mn==mn) count+=b.count;
          return {mn,__gcd(a.g,b.g),count};
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
     int n;
     cin>>n;
     vi v(n);
     inp(v);
     Tree T(n);
     rep(i,0,n){
          T.update(i,{v[i],v[i],1});
     }
     int q;
     cin>>q;
     while(q--){
          int l,r;
          cin>>l>>r;
          l--;
          struct node  val=T.query(l,r);
          if(val.mn==val.g){
               cout<<(r-l)-val.count<<endl;
               continue;
          }
          cout<<(r-l)<<endl;
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