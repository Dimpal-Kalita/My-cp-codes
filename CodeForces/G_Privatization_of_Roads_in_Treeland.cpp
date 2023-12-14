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
     ll n,k;
     cin>>n>>k;
     vector<vl>adj(n+1);
     map<pll,ll>mp;
     vector<pll>edge;
     for(int i=0;i<n-1;i++){
         ll u,v;
         cin>>u>>v;
         adj[u].pb(v);
         adj[v].pb(u);
         edge.pb({u,v});
     } 
     vector<pll>vp;
     for(int i=1;i<=n;i++){
         vp.pb({sz(adj[i]),i});
     }
     sort(all(vp),greater<pll>());
     vl mark(n+1);
     for(int i=0;i<k;i++){
          mark[vp[i].S]=1;
     }
     ll mx=0;
     function<void(ll,ll,ll)>dfs=[&](ll u,ll p,ll c){
           if(mark[u]){
               if(c==0) c++;
               for(auto v:adj[u]){
                       if(v!=p){
                            mp[{u,v}]=c;
                            mp[{v,u}]=c;
                            dfs(v,u,c);
                       }
               } 
           }else{
               ll x=1;
               for(auto v:adj[u]){
                       if(v!=p){
                            if(x==c) x++;
                            mp[{u,v}]=x;
                            mp[{v,u}]=x;
                            dfs(v,u,x);
                            x++;
                       }
               }
           }
          mx=max(mx,c);
     };
     dfs(vp[0].S,-1,0);
     cout<<mx<<endl;
     for(auto x:edge){
         cout<<mp[x]<<" ";
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