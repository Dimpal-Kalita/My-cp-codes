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


vector<vector<ll>> adj;


//calculate simple path from 1 to n

void dfs(ll u, ll n, ll &ans, vector<bool> &vis){
    if(ans==1e6){
        return;
    }
    ans++;
    vis[u]=true;
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(v, n, ans, vis);
        }
    }
    vis[u]=false;
    return;
}


void dk(){
     ll n, m;
     cin>>n>>m;
     adj.resize(n+1);
     for(ll i=0;i<m;i++){
         ll u, v;
         cin>>u>>v;
         adj[u].pb(v);
         adj[v].pb(u);
     }
     ll ans=0;
    //  for(ll i=2;i<=n;i++){
        vector<bool> vis(n+1, false);
        dfs(1, n, ans, vis);
    //     if(ans>=1e6){
    //         cout<<1e6<<endl;
    //         return;
    //       }
    // //  }

     cout<<ans<<endl;
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