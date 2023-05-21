/**
 * 
 * author: Dimpal Kalita
 * date: 20/05/2023 10:55:22
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




vector<vl> adj;
vl ans;
map<pll,ll> mp;
ll dfs(ll u, ll p=0){
     ll ct=1;
     for(auto v: adj[u]){
         if(v!=p){
             ct+=dfs(v,u);
         }
     }
     if(ct%3==0 and p!=0){
          ans.pb(mp[{u,p}]);
     }
     return ct;
}

void dk(){
      ll n;
      cin>>n;
      ans.clear();
      mp.clear();
      adj.clear();
      adj.resize(n+1);
      rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
          mp[{u,v}]=i+1;
          mp[{v,u}]=i+1;
      }
      if(n%3){
          cout<<-1<<endl;
          return;
      }
      dfs(1);
      if(ans.size()==n/3-1){
          cout<<ans.size()<<endl;
          for(auto it: ans){
              cout<<it<<" ";
          }
          cout<<endl;
          return;
      }
      cout<<-1<<endl;
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