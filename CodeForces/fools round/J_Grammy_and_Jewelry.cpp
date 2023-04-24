
#include<bits/stdc++.h>

using namespace std;


#define md                  1000000007
#define pb                  push_back
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;

const int N=1e5;
ll n, m, T; 
vector<vector<ll>>adj(N);
vector<ll> vis(N);
vector<ll> depth(N,4000);
vector<ll> cost(N, 0);


// ll recur(ll ind, ll n){


//     ll max_val=0;
//     for(int i=1;i<n;i++){
//         max_val= max(max_val, )
//     }
// }


void dk(){

    cin>>n>>m>>T;
    for(int i=0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<ll> q;
    q.push(1);
    depth[1]=0;
    while(!q.empty()){

        ll node= q.front();
        q.pop();

        if(vis[node]) continue;
        vis[node]=1;
        for(auto it:adj[node]){
            q.push(it);
            // cout<<it<<" ";
            depth[it]=min(depth[node]+1, depth[it]);
        }

    }

    // for(int i=1;i<=n;i++){
    //     cout<<depth[i]<<" ";
    // }

    ll t= T/2;
    // n = t , vector

    for(int i=1;i<=n;i++){
        cout<<depth[i]<<" ";
    }

    vector<ll> ans(t/2+1);




    cout<<endl;

}




int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}