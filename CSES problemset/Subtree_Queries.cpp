/**
 * 
 * author: Dimpal Kalita
 * date: 15/05/2023 19:04:45
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


template<class T> struct BIT {
     vector<T> s;
     int n;
     BIT(int n): s(n + 1), n(n) {}
     void update(int i, T v) {
          for (i++; i <= n; i += i & -i) s[i] += v;
     }
     T query(int i) { // EXCLUSIVE interval [0, i)
          T ans = 0;
          for (; i; i -= i & -i) ans += s[i];
          return ans;
     } // INCLUSIVE-EXCLUSIVE interval [l, r)
     T query(int l, int r) { return query(r) - query(l); }
     int kth(T k) { // 0-indexed, returns n if k > sum of tree
          if (k < 0) return -1;
          int i = 0;
          for (int pw = 1 << __lg(n); pw; pw >>= 1)
               if (i + pw <= n && s[i + pw] <= k) k -= s[i += pw];
          return i;
     }
};


map<ll,pll> mp;
ll cnt=0,n, m;
const int N= 2e5+7;
vector<vi> adj(N);
vl v(N);

void dfs(int u, int p=0){
     mp[u].F= ++cnt;
     for(auto v:adj[u]){
          if(v==p) continue;
          dfs(v,u);
     }
     mp[u].S= ++cnt;
}

void dk(){
      cin>>n>>m;
      rep(i,0,n){
          cin>>v[i];
      }
      rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
      }
      dfs(1);
      BIT<ll> bit(cnt+1);

      for(auto [x,y]:mp){
          bit.update(y.F, v[x-1]);
      }

     //  rep(i,1,n+1){
     //      cout<< bit.query(mp[i].F, mp[i].S)<<" ";
     //  }
     //  cout<<endl;

      while(m--){
          int choice;
          cin>>choice;
          if(choice==1){
               ll x, val;
               cin>>x>>val;
               bit.update(mp[x].F, val-v[x-1]);
               v[x-1]=val;
          }
          else{
               int x;
               cin>>x;
               cout<<bit.query(mp[x].F, mp[x].S)<<endl;
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