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
     typedef long long T;
     static constexpr T unit = 0;
     T f(T a, T b) { return a+b; } 
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
     vector<vl>adj(n+2);
     vector<vector<pll>>v(n+2);
     vl time(n+2);
     ll sz=1;
     Tree bt(n+1);
     for(int i=1;i<=n;i++){
         ll t;
         cin>>t;
         if(t==1){
          ll u;
          cin>>u;
          sz++;
          adj[u].pb(sz);
          time[sz]=i;
         }else{
          ll u,x;
          cin>>u>>x;
          v[u].pb({i,x});
         }
     }
     vector<ll>ans(sz+2);
     ll sum=0;

     function<void(ll,ll)> dfs=[&](ll u,ll p){
           for(auto &x:v[u]){
              ll val=bt.query(x.F,x.F+1);
              bt.update(x.F,val+x.S);
              x.S=val;
          }
          ans[u]=bt.query(time[u],n+1);
          for(auto x:adj[u]){
              dfs(x,u);
          }
          for(auto &x:v[u]){
              bt.update(x.F,x.S);
          }
     };

     dfs(1,0);
     
     for(int i=1;i<=sz;i++){
         cout<<ans[i]<<" ";
     }
     cout<<endl;

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