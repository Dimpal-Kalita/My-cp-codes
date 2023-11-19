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

void dk(){
      ll n, q;
      cin>>n>>q;
      vl v(n+1);
      rep(i,1,n+1)cin>>v[i];
      vector<vi>adj(n+1);
      rep(i,0,n-1){
           int a,b;
           cin>>a>>b;
           adj[a].pb(b);
           adj[b].pb(a);
      }
      BIT<ll>bit(3*n+1);
      vl in(n+1),out(n+1);
      ll timer=0;
      function<void(int,int)>dfs=[&](int node, int par){
           in[node]=++timer;
           for(auto child:adj[node]){
                if(child==par) continue;
                dfs(child,node);
           }
           out[node]=++timer;
      };
      dfs(1,0);
      rep(i,1,n+1){
           bit.update(in[i],v[i]);
           bit.update(out[i],-v[i]);
      }
      while(q--){
          int type;
          cin>>type;
          if(type==1){
               int s,x;
               cin>>s>>x;
               bit.update(in[s],x-v[s]);
               bit.update(out[s],v[s]-x);
               v[s]=x;
          }else{
               int s;
               cin>>s;
               cout<<bit.query(in[s]+1)<<endl;
          }
      }

}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   