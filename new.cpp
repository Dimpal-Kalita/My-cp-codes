/**
 * 
 * author: Dimpal Kalita
 * date: 02/06/2024 08:02:13
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
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
     typedef ll T;
     static constexpr T unit = 2^31-1;
     T f(T a, T b) { return a&b; } // (any associative fn)
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

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
     
     int n=nums.size();
     Tree t(n+1);
     rep(i,0,n){
          t.update(i,nums[i]);
     }
     ll ans=1e12;
     for(int i=0;i<n;i++){
          ll l=i,r=n+1;
          while(l<r){
               ll m=(l+r)/2;
               ll x=t.query(i,m);
               ans=min(ans,abs(x-k));
               if(x>=k){
                    r=m;
               }else{
                    l=m+1;
               }
          }
          ans=min(ans,abs(t.query(i,l)-(ll)k));
          ans=min(ans,abs(t.query(i,r)-(ll)k));
     }
     return ans;
    }
};



void dk(){
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