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








struct DSU{
    vector<ll> parent;
    vector<ll> size;
    ll total_components;

    void init(ll n){
        parent.resize(n);
        size.resize(n);
        for(ll i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        total_components=n;
    }

    ll get(ll a){
        if(a==parent[a]) return a;
        return parent[a]=get(parent[a]);
    }
    ll getsize(ll a){
        return size[get(a)];
    }

    void unite(ll a,ll b){
        a=get(a);
        b=get(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
            total_components--;
        }
    }
};




vector<vector<ll>>adj;
vector<ll> ans, vis;
map<ll,ll> par;
DSU dsu;


ll dfs(ll node){
    if(vis[node]) return ans[node];
    vis[node]=true;
    ll val= 0;
    for(auto x: adj[node]){
        ans[x]=max(ans[x],dfs(x)+1);
    }

    return ans[node];
}

void dk(){
     ll n, m;
     cin>>n>>m;
     vector<vector<char>>v(n,vector<char>(m));
     adj.resize(n+m);
     ans.resize(n+m);
     vis.resize(n+m);
     dsu.init(n+m);

     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             cin>>v[i][j];

             if(v[i][j]=='>') adj[j+n].pb(i);
             if(v[i][j]=='<') adj[i].pb(j+n);
        }

     }

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='='){
                dsu.unite(i, j+n);
            }
            if(dsu.get(i)==dsu.get(j+n) && v[i][j]!='='){
                cout<<"No"<<endl;
                return;
            } 
        }
     }
     for(int i=0;i<n+m;i++){
        par[i]=0;
     }

     for(int i=0;i<n+m;i++){
        if(adj.size()==0){
            ans[i]=1;
            dfs(i);
        }
     }

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='>' && ans[i]<=ans[j+n]){
                cout<<"No"<<endl;
                return;
            }
            if(v[i][j]=='<' && ans[i]>=ans[j+n]){
                cout<<"No"<<endl;
                return;
            }
            if(v[i][j]=='=' && ans[i]!=ans[j+n]){
                cout<<"No"<<endl;
                return;
            }
        }
     }
     cout<<"Yes"<<endl;
     for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
     }
     cout<<endl;
     for(int i=n;i<n+m;i++){
        cout<<ans[i]<<" ";
     }
     cout<<endl;
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