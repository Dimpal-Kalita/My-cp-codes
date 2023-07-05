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


void dk(){
        ll n,m;
        cin>>n>>m;
        vector<vector<pll>> adj(n+1);
        rep(i,0,m){
            ll x,y,z;
            cin>>x>>y>>z;
            adj[x].pb({y,z});
            adj[y].pb({x,z});
        }
        vl dist(n+1,1e18),vis(n+1);
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        pq.push({0,n});
        dist[n]=0;
        while(!pq.empty()){
            ll u=pq.top().S;
            ll d=pq.top().F;
            pq.pop();
            if(d>dist[u]) continue;
            for(auto x: adj[u]){
                ll v=x.F;
                ll w=x.S;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        if(dist[1]==1e18){
            cout<<"inf"<<endl;
            return;
        }
        cout<<dist[1]<<" ";
        set<ll>st;
        for(int i=1;i<n;i++){
            if(dist[i]<=dist[1]) st.insert(dist[i]);
        }

        cout<<sz(st)<<endl;
        ll prev=0;  
        for(auto it:st){
            for(int i=1;i<n;i++){
                if(dist[i]==1e18) cout<<0;
                else if(dist[i]>=it) cout<<1;
                else cout<<0; 
            }
            cout<<0<<" "<<it-prev<<endl;
            prev=it;
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