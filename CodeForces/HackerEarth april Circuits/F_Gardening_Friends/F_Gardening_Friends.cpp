/**
 * 
 * author: Dimpal Kalita
 * date: 26/04/2023 23:47:50
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


const int N=2*1e5+7;
ll n,k,c;
vector<vl>adj(N);
void dfs(ll node, ll par, vector<ll>&dist,ll d){
    dist[node]=max(d,dist[node]);
    
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,node,dist,d+k);
        }
    }
}
 
void dk(){
    cin>>n>>k>>c;
    rep(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> val(n+2,0);
    vector<ll> dist1(n+2,0);
    dfs(1,0,dist1,0);
    ll mx=-1,root=-1,sroot=-1;
    
    for(int i=1;i<=n;i++){
        val[i]=(dist1[i]/k)*c;
        if(dist1[i]>mx){
            mx=dist1[i];
            root=i;
        }
    }
        
    dfs(root,0,dist1,0);
    mx=-1;
    for(int i=1;i<=n;i++){
        if(dist1[i]>mx){
            mx=dist1[i];
            sroot=i;
        }
    }
    
    dfs(sroot,0,dist1,0);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dist1[i]-val[i]);
    }
    cout<<ans<<endl;

    rep(i,0,n+1) adj[i].clear();
 
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}