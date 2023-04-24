// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               ((long long)((x).size()));
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



vector<vector<pll>>adj;
vector<bool> vis;

bool check(string s){
    for(auto it: s){
        if(it!='4' && it!='7') return 0;
    }
    return 1;
}


ll cnt(ll node){
    if(vis[node]) return 0;
    vis[node]=1;
    ll ans=1;
    for(auto child: adj[node]){
        if(!vis[child.F] && child.S!=1){
            ans+=cnt(child.F);
        }
    }
    return ans;
}

void dk(){
      ll n;
      cin>>n;
      adj.resize(n+1);
      vis.resize(n+1);
      ll ct=0;
      for(int i=0;i<n-1;i++){
        ll u,v;
        string s;
        cin>>u>>v>>s;
        ll x=check(s);
        adj[u].pb({v,x});
        adj[v].pb({u,x});
        ct+=x;
      }


      ll ans= n*(n-1)*(n-2);

      for(int i=1;i<=n;i++){
         ll x=cnt(i);
         ans-= x*(x-1)*(x-2) + (x*(x-1)*(n-x))*2;
      }

      cout<<ans<<endl;
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