/**
 * 
 * author: Dimpal Kalita
 * date: 27/01/2024 18:14:39
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


template<class I> vi lis(const vector<I>& S) {
     if (S.empty()) return {};
     vi prev(sz(S));
     typedef pair<I, int> p;
     vector<p> res;
     rep(i, 0, sz(S)) {
          // change 0 -> i for longest non-decreasing subsequence
          auto it = lower_bound(all(res), p{S[i], 0});
          if (it == res.end())
               res.emplace_back(), it = res.end() - 1;
          *it = {S[i], i};
          prev[i] = it == res.begin() ? 0 : (it - 1)->second;
     }
     int L = sz(res), cur = res.back().second;
     vi ans(L);
     while (L--) ans[L] = cur, cur = prev[cur];
     return ans;
}
void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     cout<<lis(v).size()<<endl;
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