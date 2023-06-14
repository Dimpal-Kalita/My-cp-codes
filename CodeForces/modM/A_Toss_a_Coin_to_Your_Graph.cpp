/**
 * 
 * author: Dimpal Kalita
 * date: 26/05/2023 17:32:46
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

ll n,m,k;
vector<vl> adj;
vl v;


bool check_cycle(ll node,ll w,vector<ll>& vis){
     vis[node]=1;
     for(auto x: adj[node]){
          if(v[x-1]>w) continue;
          if(vis[x]==0){
               if(check_cycle(x,w,vis)) return true;
          }
          else if(vis[x]==1){
                 return true;
          }
     }
     vis[node]=2;
     return false;
}

bool check(ll w){
     vector<ll>vis(n+1,0);
     rep(i,1,n+1){
          if(v[i-1]>w) continue;
          if(!vis[i]){
               if(check_cycle(i,w,vis)) return true;
          }
     }
     return false;
}


ll DAG(ll node, ll w, vector<ll>&vis, vector<ll>&dist){
     vis[node]=1;
     ll mn=v[node-1];
     for(auto x: adj[node]){
          if(v[x-1]>w) continue;
          if(!vis[x]){
               mn= min(mn,DAG(x,w,vis,dist));
          }
          dist[node]=max(dist[node],dist[x]+1);
     }
     vis[node]=2;
     return mn;
}

bool check2(ll w){
     vector<ll> dist(n+1,1),vis(n+1,0);
     ll mn=INT_MAX;
     rep(i,1,n+1){
          if(v[i-1]>w) continue;
          if(!vis[i]){
               mn= min(mn,DAG(i,w,vis,dist));
          }
     }
     rep(i,1,n+1){
          if(v[i-1]>w) continue;
          if(dist[i]>=k && mn<=w) return true;
     }
     return false;
}

void dk(){
     cin>>n>>m>>k;
     adj.resize(n+1);
     v.resize(n);
     inp(v);     
     rep(i,0,m){
         ll u,v;
         cin>>u>>v;
         adj[u].pb(v);
     }
     if(k==1){
          cout<<*min_element(all(v))<<endl;
          return;
     }
     ll l=1,r=1e9,ans=-1;
     while(l<r){
          ll mid=(l+r)/2;
          if(check(mid) || check2(mid)){
               r=mid;
               ans=mid;
          }
          else{
               l=mid+1;
          }
     }
     cout<<ans<<endl;
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