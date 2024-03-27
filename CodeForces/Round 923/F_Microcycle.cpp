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

struct DSU {
     vector<int> s;
     DSU(int n): s(n, -1) {}
     int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
     bool join(int a, int b) {
          a = find(a), b = find(b);
          if (a == b) return false;
          if (s[a] > s[b]) swap(a, b);
          s[a] += s[b], s[b] = a;
          return true;
     }
     int size(int i) { return -s[find(i)]; }
     bool same(int a, int b) { return find(a) == find(b); }
};

void dk(){
     ll n,m;
     cin>>n>>m;
     vector<array<ll,3>>v;
     vector<vl>adj(n+1);
     rep(i,0,m){
          ll a,b,c;
          cin>>a>>b>>c;
          adj[a].pb(b);
          adj[b].pb(a);
          v.pb({c,a,b});
     }
     sort(all(v),greater<array<ll,3>>());
     DSU dsu(n+1);
     ll start,end,mn;
     rep(i,0,m){
          if(!dsu.join(v[i][1],v[i][2])){
               start=v[i][1];
               end=v[i][2];
               mn=v[i][0];
          }
     }
     vl par(n+1),vis(n+1);
     function<void(ll,ll)>dfs=[&](ll node, ll parent){
          par[node]=parent;
          vis[node]=1;
          for(auto x: adj[node]){
               if(x==parent) continue;
               if(x==end){
                    par[x]=node;
                    return;
               }else{
                    if(!vis[x]){
                         dfs(x,node);
                    }
               }
          }
     };
     dfs(start,end);
     ll node=end;
     vl ans;
     while(node!=start){
          ans.pb(node);
          node=par[node];
     } 
     ans.pb(start);
     cout<<mn<<" "<<ans.size()<<endl;
     for(auto i:ans){
          cout<<i<<" ";
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