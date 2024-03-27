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


#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif


struct Tree {
     typedef long long T;
     static constexpr T unit = 0;
     T f(T a, T b) { return a+b;} // (any associative fn)
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
     v.pb(0);
     Tree t(n+2);
     rep(i,0,n+1){
          t.update(i,v[i]);
     }
     auto check=[&](ll mid)->bool{
          vl dp(n+2,0);
          dp[0]=0;
          deque<ll> dq;
          for(int i=0;i<=n;i++){
               while(!dq.empty() and dp[dq.back()]>=dp[i]) dq.pop_back();
               dq.pb(i);
               while(!dq.empty() and t.query(dq.front(),i)>mid) dq.pop_front();
               dp[i+1]=dp[dq.front()]+v[i];
          }
          return dp[n+1]<=mid;
     };
     ll l=*max_element(all(v)),r=1e15;
     while(l<r){
          ll mid=(l+r)/2;
          if(check(mid)){
               r=mid;
          }else{
               l=mid+1;
          }
     }
     cout<<r<<endl;
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