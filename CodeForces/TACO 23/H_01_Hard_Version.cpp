/**
 * 
 * author: Dimpal Kalita
 * date: 22/05/2023 18:44:29
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


typedef struct T{
     ll zero,one;
}T;

struct Tree {
     static constexpr T unit = {0,0};
     T f(T a, T b) { return {b.zero+max(0ll,a.zero-b.one),a.one+max(0ll,b.one-a.zero)};} // (any associative fn)
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
      string s;
      cin>>s;
      int n=s.size();
      Tree tr(n);
      for(int i=0;i<n;i++){
           if(s[i]=='1'){
                tr.update(i,{0,1});
           }
           else{
                tr.update(i,{1,0});
           }
      }
      int q;
      cin>>q;
      while(q--){
          int ch;
          cin>>ch;
          if(ch==1){
               int ind;
               cin>>ind;
               ind--;
               if(s[ind]=='1'){
                    s[ind]='0';
                    tr.update(ind,{1,0});
               }
               else{
                    s[ind]='1';
                    tr.update(ind,{0,1});
               }
          }else{
               ll l,r;
               cin>>l>>r;
               l--,r--;
               T ans=tr.query(l,r+1);
               cout<<ans.one+ans.zero<<endl;
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