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
vector<ll> ans;




bool cycle(ll u){
    vis[u]=1;
    for(auto v: adj[u]){
        if(vis[v]==0){
            if(cycle(v)) return true;
        }
        else if(vis[v]==1) return true;
    }
    vis[u]=2;
    return false;
}



void dfs(ll node , ll par){
    vis[node]=1;   
    
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i, node);
        }
    }

    ans.pb(node);
}


void dk(){
     ll n,m;
     cin>>n>>m;
     adj.resize(n+1);
     vis.resize(n+1);

     for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
     }
     
     bool c=0;

     for(ll i=1;i<=n;i++){
          if(!vis[i]){
                if(cycle(i)){
                    c=1;
                    break;
                }
          }
     }

     if(c){
        cout<<"IMPOSSIBLE"<<endl;
        return;
     }

    
     vis.clear();
     vis.resize(n+1, 0);

     for(ll i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i, -1);
        }
     }
     reverse(all(ans));
     for(auto i:ans){
        cout<<i<<" ";
     }
     cout<<endl;

      


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