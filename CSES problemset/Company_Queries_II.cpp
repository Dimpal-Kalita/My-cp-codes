// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

struct LCA{
    int n;
    vector<vector<int>> up;
    vector<int> tin, tout;
    int timer;
    LCA(int n): n(n), tin(n), tout(n), timer(0){
        up.assign(n, vector<int>(log2(n)+1));
    }
    void dfs(int v, int p, vector<vector<int>> &adj){
        tin[v] = ++timer;
        up[v][0] = p;
        for(int i = 1; i < up[v].size(); i++){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for(int u: adj[v]){
            if(u != p){
                dfs(u, v, adj);
            }
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v){
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v){
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        for(int i = up[u].size()-1; i >= 0; i--){
            if(!is_ancestor(up[u][i], v)){
                u = up[u][i];
            }
        }
        return up[u][0];
    }
};


void dk(){
      int n, q;
      cin>>n>>q;
      vector<int> v(n-1);
      inp(v);
      vector<vector<int>>adj(n+1);
      for(ll i=2;i<=n;i++){
            adj[i].pb(v[i-2]);
            adj[v[i-2]].pb(i);
      }
      LCA lca(n+1);
      lca.dfs(1, 1, adj);
      while(q--){
        ll a, b;
        cin>>a>>b;
        cout<<lca.lca(a, b)<<endl;
      }
      


}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}