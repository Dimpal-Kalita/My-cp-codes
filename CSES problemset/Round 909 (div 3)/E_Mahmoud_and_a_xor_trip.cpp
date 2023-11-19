#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


const int N=1e5+2;
ll n;
vl v(N);
vector<vi>adj(N);
vi subtree(N),level(N);
ll ans=0;

ll getSize(int node,int par=-1){
     ll sz=1;
     for(auto child:adj[node]){
          if(child!=par and !level[node]){
               sz+=getSize(child,node);
          }
     }
     return subtree[node]=sz;
}

ll Centroid(ll node, ll par, ll sz){
     for(auto child:adj[node]){
          if(child!=par && subtree[child]>sz/2 and !level[child]){
               return Centroid(child,node,sz);
          }
     }
     return node;
}


ll mx=0;
void dfs(ll node,ll d,bool flag, ll par=-1){


     for(auto child:adj[node]){
          if(child!=par and !level[child]){
          
          }
     }
}




void decompose(ll node,ll l){
     ll cent=Centroid(node,-1,getSize(node));
     level[cent]=l;
     for(auto child:adj[node]){
          if(!level[child]){
               decompose(child,l+1);
          }
     }
}



void dk(){
     cin>>n;
     rep(i,1,n+1){
          cin>>v[i];
     }
     rep(i,0,n-1){
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }

}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   