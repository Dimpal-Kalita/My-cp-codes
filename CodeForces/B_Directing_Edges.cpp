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
     vector<vl>adj(n+1),graph(n+1);
     map<pll,ll>mp;
     map<ll,pll>ans;
     vl in(n+1,0);
     rep(i,0,m){
          ll t,u,v;
          cin>>t>>u>>v;
          if(t){
               adj[u].pb(v);
               in[v]++;
               ans[i]={u,v};
          }else{
               graph[u].pb(v);
               graph[v].pb(u);
               mp[{u,v}]=i;
               mp[{v,u}]=i;
          }
     }
     queue<int>q;
     vl t;
     rep(i,1,n+1){
          if(in[i]==0){
               q.push(i);
               t.pb(i);
          }
     }
     while(!q.empty()){
          auto node=q.front();
          q.pop();
          for(auto it:adj[node]){
               in[it]--;
               if(in[it]==0){
                    q.push(it);
                    t.pb(it);
               }
          }
     }
     rep(i,1,n+1){
          if(in[i]>0){
               cout<<"NO"<<endl;
               return;
          }
     }
     map<pll,ll>vis;
     cout<<"YES"<<endl;
     
     for(auto i:t){
          q.push(i);
     }
     
     while(!q.empty()){
          auto node=q.front();
          q.pop();
          for(auto it:graph[node]){
              if(!ans.count(mp[{node,it}])) ans[mp[{node,it}]]={node,it};
          }
     }
     for(auto it:ans){
          cout<<it.S.F<<" "<<it.S.S<<endl;
     }
}




int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   