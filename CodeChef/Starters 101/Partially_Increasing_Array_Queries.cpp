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

template<class T, int... Ns> struct BIT {
  T val = 0;
  void update(T v) { val += v; }
  T query() { return val; }
};
template<class T, int N, int... Ns> struct BIT<T, N, Ns...> {
  BIT<T, Ns...> bit[N + 1];
  // map<int, BIT<T, Ns...>> bit; // if the mem use is too high
  template<class... Args> void update(int i, Args... args) {
    for (i++; i <= N; i += i & -i) bit[i].update(args...);
  }
  template<class... Args> T query(int i, Args... args) {
    T ans = 0;
    for (i++; i; i -= i & -i) ans += bit[i].query(args...);
    return ans;
  }
  template<class... Args,
    enable_if_t<(sizeof...(Args) == 2 * sizeof...(Ns))>* =
      nullptr>
  T query(int l, int r, Args... args) {
    return query(r, args...) - query(l - 1, args...);
  }
};

void dk(){
      BIT<int, 2> bit;

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