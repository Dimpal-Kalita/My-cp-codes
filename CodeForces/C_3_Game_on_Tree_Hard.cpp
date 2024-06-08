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

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n,t;
     cin>>n>>t;
     vector<vl>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     vl ret(n+1);
     function<bool(ll,ll)>dfs=[&](ll node, ll par)->bool{
          ll ans=0; 
          for(auto x:adj[node]){
               if(x==par) continue;
               ll y=dfs(x,node);
               ans+=(y==0);
          }
          return ret[node]=ans;
     };  
     vl ans(n+1);
     function<void(ll,ll)>dfs2=[&](ll node, ll par)->void{
          ans[node]=(ret[node]>0);
          for(auto child:adj[node]){
               if(child==par) continue;;
               ret[node]-=(ret[child]==0);
               ret[child]+=(ret[node]==0);
               dfs2(child,node);
               ret[child]-=(ret[node]==0);
               ret[node]+=(ret[child]==0);
          }
          return;
     };  
     
     dfs(1,0);
     // debug(ret);
     dfs2(1,0);
     rep(i,0,t){
          ll node;
          cin>>node;
          cout<<(ans[node]?"Ron":"Hermione")<<endl;
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