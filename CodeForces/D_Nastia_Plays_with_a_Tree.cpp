#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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
     ll n;
     cin>>n;
     vector<vl> adj(n+1);
     vl degree(n+1);
     rep(i,0,n-1){
          ll a,b;
          cin>>a>>b;
          adj[a].pb(b);
          adj[b].pb(a);
          degree[a]++;
          degree[b]++;
     } 

     set<pll>ans;
     vl leaf;
     function<ll(ll,ll)> dfs=[&](ll u,ll p)->ll{
          vl temp;
          for(auto v: adj[u]){
               if(v==p) continue;
               ll get=dfs(v,u);
               if(get) temp.pb(v);
          }
          ll ret=1;
          ll ct=temp.size();
          if(ct>=2){
               if(p!=-1){
                    ans.insert({p,u});
                    degree[p]--;
                    degree[u]--;
                    ret=0;    
               }
               for(int i=2;i<temp.size();i++){
                    ans.insert({u,temp[i]});
                    degree[u]--;
                    degree[temp[i]]--;
               }
          }
          return ret;
     };
     dfs(1,-1);
     cout<<ans.size()<<endl;
     DSU dsu(n+1);

     function<void(ll,ll)> dfs2=[&](ll u,ll p)->void{
          if(p!=-1 and !ans.count({p,u})){
               dsu.join(p,u);
          }
          for(auto v: adj[u]){
               if(v==p) continue;
               dfs2(v,u);
          }
          return;
     };

     debug(leaf);
     dfs2(1,-1);
     vector<pll>connect;
     while(sz(connect)<sz(ans)){
          vl joinleaf;
          rep(i,1,n+1) if(degree[i]<=1) joinleaf.pb(i);
          for(int i=1;i<joinleaf.size();i++){
               if(degree[joinleaf[i]]==2 or degree[joinleaf[i-1]]==2) continue;
               if(dsu.same(joinleaf[i],joinleaf[i-1])) continue;
               connect.pb({joinleaf[i],joinleaf[i-1]});
               dsu.join(joinleaf[i],joinleaf[i-1]);
               degree[joinleaf[i]]++;
               degree[joinleaf[i-1]]++;
          }
     }
     vector<pll>disconnect(all(ans));
     rep(i,0,connect.size()){
          cout<<disconnect[i].F<<" "<<disconnect[i].S<<" "<<connect[i].F<<" "<<connect[i].S<<endl;
     }
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