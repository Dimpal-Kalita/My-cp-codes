// 2112048
// Dimpal Kalita
// CSE sec A

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
vector<ll> vis;
vector<pll> ans;
void bfs(ll x){
  queue<ll> q;
  q.push(x);
  while(!q.empty()){
      ll node= q.front();
      q.pop();
      vis[node]=1;
      for(auto i:adj[node]){
        if(!vis[i]){
          q.push(i);
          vis[i]=1;
          ans.pb({node, i});
        }  
      }
  }

}
void dk(){  
    ll n, m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1, 0);
    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll mx=0;
    for(ll i=1;i<=n;i++){
        if(adj[i].size()>mx){
            mx=adj[i].size();
        }
    }
    for(ll i=1;i<=n;i++){
        if(adj[i].size()==mx){
          bfs(i);
          break;
        }
    }

    for(auto i:ans) cout<<i.F<<" "<<i.S<<endl;


  
      


}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    //cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}