// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               ((long long)((x).size()));
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

const int N=1e5+7;

vector<ll> adj[N];


struct LCA{
    int n;
    vector<vector<int>> up;
    vector<int> tin, tout;
    int timer;
    LCA(int _n) : n(_n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(20));
    }
    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 20; i++)
            up[v][i] = up[up[v][i-1]][i-1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = 19; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        int w = lca(u, v);
        return depth(u) + depth(v) - 2 * depth(w);
    }
    int depth(int v) {
        return tin[v];
    }
};


map<ll,ll> mp;


map<pll,ll> ans;

ll dfs(ll node, ll par){

    ll sum=mp[node];
    // cout<<node<<" "<<mp[node]<<endl;
    for(auto x: adj[node]){
        if(x!=par){
        sum+=dfs(x, node);
        }
    }

    ans[{node, par}]=sum;
    return sum;
}



void dk(){
      int n;
      cin>>n;
      vector<pll> ques;
      for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        ques.pb({u,v});
      }

      LCA lca(n);
      lca.dfs(0, 0);

      int q;
      cin>>q;
      while(q--){
        int x, y;
        cin>>x>>y;
        x--, y--;
        int l=lca.lca(x, y);
        mp[l]-=2;
        mp[x]++, mp[y]++;
      }

      dfs(0,0);


      for(auto it: ques){
        pii x={it.S,it.F};
        cout<<max(abs(ans[x]), abs(ans[it]))<<" ";
      }
}




int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}