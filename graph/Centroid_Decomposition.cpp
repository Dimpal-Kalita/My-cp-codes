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




int n;
vector<vector<int>> adj;
vector<int> sub_sz;



void sub(int node, int par=-1){

    for(int ch:adj[node]){
        if(ch==par) continue;

        sub(ch,node);
        sub_sz[node]+= sub_sz[ch];

    }
    sub_sz[node]++;
}


int get_centroid(int node,int par=-1){
    
    for(auto it:adj[node]){
        if(it==par) continue;
        if(sub_sz[it]*2>n){
            // cout<<it<<" ";
            return get_centroid(it, node);
        }
    }

    return node;
}




void dk(){
    cin>>n;
    adj.resize(n+1);
    sub_sz.resize(n+1);
    for (int i = 0; i < n-1; ++i){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    sub(1);
    // debug(sub_sz)

    cout<<get_centroid(1)<<endl;

}



int main()
{ 
    fast_io;
    
    //#ifndef IGNOREME
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