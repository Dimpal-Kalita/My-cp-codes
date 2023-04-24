// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using pii = pair<int,int>;
using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using vl  = vector<ll>;



template<class T>
pair<vector<bool>, vector<T>> dijkstra(
    const vector<vector<pair<int, T>>>& adj, int s) {
    using ST = pair<T, int>;
    priority_queue<ST, vector<ST>, greater<ST>> q;
    vector<T> dist(adj.size(),1e18);
    dist[s]=0;
    vector<bool> seen(adj.size());
    q.emplace(T{}, s);
    seen[s] = 1;
    while (!q.empty()) {
        // auto [d, u] = q.top();
        auto xx=q.top();
        T d=xx.F;
        int u=xx.S;
        q.pop();
        if (dist[u] < d) continue;
        for (auto it : adj[u]){
            int v=it.F;
            ll w=it.S;
            if (!seen[v] || d + w < dist[v]) {
                q.emplace(dist[v] = d + w, v);
                seen[v] = 1;
            }
        }
    }
    return {seen, dist};
}



void dk(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>>adj(n+1);
    int s,t;
    cin>>s>>t;
    rep(i,0,m){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    vector<ll> dp1=dijkstra(adj,s).S;
    vector<ll> dp2=dijkstra(adj,t).S;
    int q;
    cin>>q;
    ll real=dp1[t];
    while(q--){
        ll x,y,w;
        cin>>x>>y>>w;
        ll ans=min({min(dp1[y],dp1[x]+w)+dp2[y], min(dp1[x],dp1[y]+w)+dp2[x],real});
        cout<<(ans==1e18?-1:ans)<<endl;
    }

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