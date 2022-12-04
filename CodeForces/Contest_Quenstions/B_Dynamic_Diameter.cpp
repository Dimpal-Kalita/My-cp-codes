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
vector<ll> dist;

void dfs(ll node, ll par, ll dis){
    dist[node]=max(dis, dist[node]);
    for(auto x: adj[node]){
        if(x!=par){
            dfs(x, node, dis+1);
        }
    }
}


void dk(){
        ll n;
        cin>>n;
        adj.resize(n+1);
        dist.assign(n+1, 0);

        fr(i, n-1){
            ll u, v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(1, -1, 0);

        ll ind=0;
        for(ll i=1;i<=n;i++){
            if(dist[i]>dist[ind]){
                ind=i;
            }
        }

        ll point= ind;
        dist.assign(n+1, 0);
        dfs(ind, -1, 0);
        ll dia=0;
        ind=0;

        // calaculate the maximum distance of the nodes from both the nodes of diameter
        // so that we can determine if the disatance will increase with the adding of a new edge
        for(int i=1;i<=n;i++){
            dia= max(dist[i], dia);
        }
        for(ll i=1;i<=n;i++){
             if(dist[i]>dist[ind]){
                ind=i;
            }
        }

        dfs(ind, -1, 0);
        for(ll i=1;i<=n;i++){
            if(dist[i]==dia){
                cout<<dia+1<<endl;
            }
            else cout<<dia<<endl;
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