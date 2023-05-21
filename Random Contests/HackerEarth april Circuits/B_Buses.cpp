/**
 * 
 * author: Dimpal Kalita
 * date: 30/04/2023 20:06:25
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




bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) { 
    return (a.second < b.second); 
}
map<ll,ll> dp;
void dk(){
      ll n, m;
      cin>>n>>m;
      vector<pll> vp;
      rep(i,0,m){
          ll x,y;
          cin>>x>>y;
          vp.pb({x,y});
      }
      sort(all(vp), sortbysec);
      vector<pll> ps(m+1,0);
      for(auto it:vp){
          ps[it.F+1]+=it.S;
      }

      map<ll,ll> mp;

      for(int i=0;i<n;i++){
        mp[i+1]=ps[i+1].second;
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