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


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


const int N=100000;

vector<pii> adj[N];
vector<vector<int>> dist(N, vector<int>(2, 1e6));

void dk(){
     ll n, m;
     cin>>n>>m;

     for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].pb({v,0});
        adj[v].pb({u,1});
     }
     int x, y;
     cin>>x>>y;
     priority_queue<pii, vector<pii>, greater<pii>>pq;
     
     dist[x][1]=0;
     dist[x][0]=0;
     pq.push({x,0});
     pq.push({x,1});
     
    
     while(!pq.empty()){
        auto node= pq.top();
        pq.pop();

        for(auto child:adj[node.F]){

            int distance=dist[node.F][node.S];
            if(child.S!=node.S) distance= dist[node.F][node.S]+1;

            if(dist[child.F][child.S]>distance){
                dist[child.F][child.S]=distance;
                pq.push(child);
            }
        }
     }

     cout<<min(dist[y][0], dist[y][1])<<endl;


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