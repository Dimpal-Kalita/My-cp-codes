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

vector<vector<int>> adj;
vector<set<int>> col;
vector<int> ans;
void dfs(int node, int par){

    for(auto child:adj[node]){
        if(child!=par){
            dfs(child, node);

            if(col[child].size()>col[node].size()) swap(col[child], col[node]);
            for(auto x:col[child]) col[node].insert(x);
        }
    }
    ans[node]= col[node].size();
}




void dk(){
    int n;
    cin>>n;
    adj.resize(n+1);
    col.resize(n+1);
    ans.resize(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        col[i+1].insert(x);
    }
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);
    // cout<<1<<" ";

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";

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