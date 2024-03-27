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


void dk(){
     ll n;
     cin>>n;
     vector<vl>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     } 
     ll start=0,end=0,mxdist=0;
     auto find_diameter=[&]()->void{
          vector<bool>vis(n+1,0);
          vector<ll>dist(n+1,0);
          queue<ll>q;
          q.push(1);
          vis[1]=1;
          while(!q.empty()){
               ll u=q.front();
               q.pop();
               for(auto x:adj[u]){
                    if(!vis[x]){
                         vis[x]=1;
                         dist[x]=dist[u]+1;
                         q.push(x);
                    }
               }
          }
          ll mx=0;
          rep(i,1,n+1){
               if(dist[i]>mx){
                    mx=dist[i];
                    start=i;
               }
          }
          vis.assign(n+1,0);
          dist.assign(n+1,0);
          q.push(start);
          vis[start]=1;
          while(!q.empty()){
               ll u=q.front();
               q.pop();
               for(auto x:adj[u]){
                    if(!vis[x]){
                         vis[x]=1;
                         dist[x]=dist[u]+1;
                         q.push(x);
                    }
               }
          }
          mx=0;
          rep(i,1,n+1){
               if(dist[i]>mx){
                    mx=dist[i];
                    end=i;
               }
          }
          mxdist=mx;
     };
     find_diameter();
     vector<ll>par(n+1);
     vector<ll>dist(n+1,-1);
     function<bool(ll,ll,ll)> dfs=[&](ll node, ll p,ll d)->bool{
          par[node]=p;
          for(auto x:adj[node]){
               if(x==p) continue;
               if(dfs(x,node,d+1)){
                    dist[node]=d;
                    return 1;
               }
          }
          if(node==end){
               dist[node]=d;
               return 1;    
          }
          return 0;
     };
     dfs(start,0,0);
     ll red=(mxdist+1)%2,black=0;
     vector<char>ans(n+1,'G');
     
     function<void(ll,ll,ll)> dfs2=[&](ll node, ll p,ll d)->void{
          if(dist[node]!=-1){
               if(dist[node]<=mxdist/2) ans[node]='R';
               else ans[node]='B';
          }else{
               if(red<=black) ans[node]='R',red++;
               else ans[node]='B',black++;
          }
          for(auto x:adj[node]){
               if(x==p) continue;
               dfs2(x,node,d+1);
          }
     };
     dfs2(start,0,0);
     rep(i,1,n+1) cout<<ans[i];
     cout<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   