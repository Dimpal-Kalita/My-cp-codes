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




const int N=5e5+5;
ll n,m;
vector<vi>adj(N+1);
vl v(N+1);

vector<pll> vp;
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
               vp.pb({v,to});
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(N, false);
    tin.assign(N, -1);
    low.assign(N, -1);
    for (int i = 0; i < N; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void dk(){
     cin>>n>>m;
     rep(i,0,m){
          cin>>v[i];
     }
     map<pll,ll>mp;
     rep(i,0,m){
           int u,v;
           cin>>u>>v;
           adj[u].pb(v);
           adj[v].pb(u);
           mp[{u,v}]=i;
           mp[{v,u}]=i;
     }
     find_bridges();
     vector<ll>ans;
     for(auto x:vp){
          ans.pb(v[mp[x]]);
     }
     sort(all(ans));
     ll mx=0,mn=0;
     for(int i=0;i<ans.size();i++){
          if(i%2) mx+=ans[i];
          else mn+=ans[i];
     }
     cout<<max(mx,mn)<<" "<<min(mx,mn)<<endl;
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