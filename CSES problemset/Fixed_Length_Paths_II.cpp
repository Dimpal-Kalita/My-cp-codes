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
};


ll n,k1,k2;
vector<vi>adj;
vi level,subtree;
ll ans=0,mx=0;
BIT<ll>bit(2e5+1);


int getSize(int node, int par=-1){
     subtree[node]=1;
     for(auto child:adj[node]){
          if(child==par or level[child]) continue;
          subtree[node]+=getSize(child,node);
     }
     return subtree[node];
}
int centroid(int node, int r, int par =-1){
     for(auto child:adj[node]){
          if(child==par or level[child]) continue;
          if(subtree[child]*2>r) return centroid(child,r,node);
     }
     return node;
}



void dfs(int node,int par,ll d,bool flag){
     if(k2<d) return;

     if(flag){
          bit.update(d,1);
     }else{
          ans+=bit.query(max(k1,d)-d,k2-d+1);
     }
     mx=max(mx,d);

     for(auto child:adj[node]){
          if(child==par || level[child]) continue;
          dfs(child,node,d+1,flag);
     }
}


int decompose(int node, int l){
     int cent=centroid(node,getSize(node));
     
     level[cent]=l;
     mx=0;
     bit.update(0,1);

     for(auto child:adj[cent]){
          if(level[child]) continue;
          dfs(child,cent,1,0);
          dfs(child,cent,1,1);
     }

     for(int i=0;i<=mx+2;i++){
          ll x=bit.query(i,i+1);
          bit.update(i,-x);
     }

     for(auto child:adj[cent]){
          if(!level[child]) decompose(child,l+1);
     }
     return cent;
}




void dk(){
     cin>>n>>k1>>k2;
     adj.assign(n+1,vi());
     level.assign(n+1,0);
     subtree.assign(n+1,0);
     rep(i,0,n-1){
          int u,v; cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     decompose(1,1);
     cout<<ans<<endl;
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