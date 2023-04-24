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




vector<ll> ans;
void dfs(ll u, vector<vector<ll>> &adj, vector<ll> &vis, ll dist, ll req){
    vis[u]=1;
    // cout<<u<<" "<<dist<<" /";
    if(dist>=req+1){
        dist=0;
        ans.pb(u);
    }
    dist++;
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(v, adj, vis, dist, req);
        }
    }
}




void dk(){
     ll n,m;
     cin>>n>>m;
     ans.clear();
     vector<vector<ll>>adj(n+1);

     for(int i=0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
     }
     vector<ll> vis(n+1,0);
     ll x= ceil(sqrt(n));
     
     ans.pb(1);
     dfs(1, adj, vis, 0, x);
     
     cout<<ans.size()<<endl;
     for(auto it:ans){
        cout<<it<<" ";
     }
     cout<<endl;

}




int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}