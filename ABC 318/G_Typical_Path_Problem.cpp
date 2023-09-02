/**
 * 
 * author: Dimpal Kalita
 * 
 */

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



using pbb =pair<bool,bool>;



ll n,m;
vector<vl>adj;
vector<bool>vis;
ll a,b,c;

pbb dfs(ll node){
     if(vis[node]) return {0,0};
     vis[node]=1;
     if(node==a) return {1,0};
     if(node==c) return {0,1}; 
     pbb ans1={0,0},ans2={0,0};     
     for(auto child:adj[node]){
          pbb temp=dfs(child);
          ans1.F|=temp.F;
          ans1.S|=temp.S;
     }
     if(ans1.F==1){
          return ans1;
     }else if(ans2.S==1){
          return ans2;
     }
     return {0,0};
}


void dk(){
     cin>>n>>m;
     adj.resize(n+1);
     vis.resize(n+1);
     cin>>a>>b>>c;
     rep(i,0,m){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }

     ll ans=0;
     vis[b]=1;
     for(auto i:adj[b]){
          pbb temp=dfs(i);
          ans+=temp.F;
          ans+=temp.S;
     }
     if(ans==2){
          cout<<"Yes"<<endl;
     }
     else{
          cout<<"No"<<endl;
     }
     
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}