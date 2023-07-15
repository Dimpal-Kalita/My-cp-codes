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
     typedef  struct node {
          int mn, count;
     }  T;
     static constexpr T unit = {INT_MAX,1};
     T f(T a, T b) { 
          T temp={INT_MAX,0};
          temp.mn=min(a.mn,b.mn);
          if(a.mn==temp.mn) temp.count+=a.count;
          if(b.mn==temp.mn) temp.count+=b.count;
          return temp;
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
      int n,q;
      cin>>n>>q;
      Tree tree(n);
      rep(i,0,n) {
          int x;
          cin>>x;
          tree.update(i,{x,1});
      } 
      while(q--){
          int t;
          cin>>t;
          if(t==1){
              int k,u;
              cin>>k>>u;
              tree.update(k,{u,1});
          }
          else{
              int a,b;
              cin>>a>>b;
              cout<<tree.query(a,b).mn<<" "<<tree.query(a,b).count<<endl;
          }
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