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


 
ll timer;
vector<ll> tin, tout;
 
vector<vector<ll>>adj;
vector<ll> ans;

void dfs(ll node, ll par){
    tin[node]= ++timer;
    ans.pb(node);
    for(auto child:adj[node]){
        if(child==par) continue;
        dfs(child, node);
    }
    tout[node]= ++timer;
}



void dk(){
      ll n, q;
      cin>>n>>q;
      adj.resize(n+1);
      tin.resize(n+1);
      tout.resize(n+1);
      fr(i, n-1){
        ll x;
        cin>>x;
        adj[x].pb(i+2);
        adj[i+2].pb(x);
      }
      ans.pb(0);
      fr(i,n+1) sort(all(adj[i]));
      dfs(1,0);
      map<ll,ll> mp;
      fr(i, n+1) mp[ans[i]]=i;
    //   debug(ans);
      
      while(q--){
        ll u, k;
        cin>>u>>k;
        ll ind= mp[u];
        ll req= ind+k-1;

        if(req>n){
            cout<<-1<<endl;
            continue;
        }
        
        ll node= ans[req];
        // cout<<node<<" ";
        if(tin[node]>=tin[u] && tout[node]<=tout[u]){
            cout<<node<<endl;
            continue;
        }
        cout<<-1<<endl;

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