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
#define sz(x)             int((x).size());
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key




vector<vector<ll>> adj;
vector<ll> vis;


pll dfs(ll node){
    if(vis[node]) return {0,0};
    vis[node]=1;
    ll val=1;    
    ll ans= adj[node].size();
    for(auto it:adj[node]){
        pll x= dfs(it);
        ans+=x.F;
        val+=x.S;
    }

    return {ans,val};
}

void dk(){
    ll n, m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,0);

    for(int i=0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]) continue;

         pll val=dfs(i);
         if(val.F%2!=0 || (val.S!=(val.F/2))){
            cout<<"No"<<endl;
            return;
        }
    }


    cout<<"Yes"<<endl;

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