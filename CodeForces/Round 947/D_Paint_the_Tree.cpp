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


vector<vl>adj;      
ll n;
ll x,y;

ll depth(ll u,ll p){
     ll d=0;
     for(auto v:adj[u]){
          if(v==p) continue;
          d=max(d,depth(v,u)+1);
     }
     return d;
}

ll dist(ll u,ll p,ll end){
     if(u==end) return 1;
     ll d=0;
     for(auto v:adj[u]){
          if(v==p) continue;
          d=max(d,dist(v,u,end));
     }
     if(d) d++;
     return d;
}

// find meeting point of start node and end node in d/2 distance from both of them

ll meet;
ll findmeetingpoint(ll u,ll p,ll end,ll d){
     if(u==end) return 1;
     ll ans=0;
     for(auto v:adj[u]){
          if(v==p) continue;
          ans=max(ans,findmeetingpoint(v,u,end,d));
     }
     if(ans){
          if(ans==(d+1)/2) meet=u;
          ans++;
     }
     return ans;
}

ll calc(ll u,ll p){
     ll d=0;
     for(auto v:adj[u]){
          if(v==p) continue;
          d+=calc(v,u);
     }
     if(meet==u) return d;
     return d+2;
}
void dk(){
     cin>>n;
     adj.assign(n+1,vl());
     cin>>x>>y;

     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     meet=y;
     ll d=dist(x,0,y);
     d--;
     findmeetingpoint(x,0,y,d);
    //  cout<<d<<endl;
     ll ans=calc(meet,0)-depth(meet,0)+(d+1)/2;
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