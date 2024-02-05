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


using arr=array<ll,3>;
void dk(){
     ll n,m;
     cin>>n>>m;
     vector<vector<pll>> adj(n+1);
     for(int i=0;i<m;i++){
          ll u,v,w;
          cin>>u>>v>>w;
          adj[u].pb({v,w});
          adj[v].pb({u,w});
     }
     vector<ll>s(n+1);
     rep(i,1,n+1) cin>>s[i];

     vector<vl>dist(n+1,vl(n+1,1e18));
     
     priority_queue<arr,vector<arr>,greater<arr>>pq;
     pq.push({0,1,1});
     dist[1][1]=0;
     while(!pq.empty()){
          auto [d,ind,u]=pq.top();
          pq.pop();
          if(dist[u][ind]<d) continue;
          if(s[u]<s[ind]) ind=u;
          for(auto [v,w]:adj[u]){
               if(dist[v][ind]>d+w*s[ind]){
                    dist[v][ind]=d+w*s[ind];
                    pq.push({dist[v][ind],ind,v});
               }
          }
     }
     
     ll ans=1e18;
     for(int i=1;i<=n;i++){
          ans=min(ans,dist[n][i]);
     }
     cout<<ans<<endl;
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