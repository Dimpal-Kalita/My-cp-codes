/**
 * 
 * author: Dimpal Kalita
 * date: 19/05/2023 21:29:19
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



const int maxx = 2*1e5+10;
ll n;
vector<vl> graph;
vector<bool> vis;

ll cnt = 0 , cnt1 = 0;
void dfs(ll node){
    cnt1++;
    vis[node] = true;
    for(auto it: graph[node]){
        if(!vis[it]){
            dfs(it);
        }
        cnt++;
    }
}

void dk(){
    cin >> n;
    set<ll> adj[n+1];
    for(int i = 1 ; i <= n ; i ++){
        ll x; cin >> x;
        adj[x].insert(i);
        adj[i].insert(x);
    }
    graph.clear();
    graph.resize(n+1);
    vis.assign(n+1 , false);
    for(int i = 1 ; i <= n ; i++ ){
        for(auto it: adj[i]){
            graph[i].pb(it);
        }
    }
    ll cycle = 0 , chain = 0;
    for(int i = 1; i <= n ; i++){
        if(!vis[i]){
            cnt = 0 , cnt1 = 0;
            dfs(i);
            cnt/=2;
            if(cnt == cnt1){
                cycle++;
            }else{
                chain++;
            }
        }
    }
    ll maxx = cycle+chain;
    ll minn = cycle+(chain>0);
    cout << minn << " " << maxx << endl;

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