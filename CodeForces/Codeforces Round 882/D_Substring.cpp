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


int n,m;
vector<set<int>>adj;
vi col,vis;
string s;

bool cycle(int node){
     col[node]=1;
     for(auto child:adj[node]){
          if(col[child]==1) return true;
          if(col[child]==0 && cycle(child)) return true;
     }
     col[node]=2;
     return false;
}


map<int,vi>dp;
int ans=0;
vi dfs(int node){

     if(vis[node]==1) return dp[node]; 
     
     vis[node]=1;
     vi cnt(26,0);
     for(auto child:adj[node]){
          vi temp=dfs(child);
          for(int i=0;i<26;i++){
               cnt[i]=max(temp[i],cnt[i]);
          }    
     }

     cnt[s[node-1]-'a']++;
     rep(i,0,26){
          ans=max(ans,cnt[i]);
     }

     return dp[node]=cnt;
}

void dk(){
     cin>>n>>m;
     adj=vector<set<int>>(n+1);
     col=vis=vi(n+1,0);
     cin>>s;
     for(int i=0;i<m;i++){
          int u,v;
          cin>>u>>v;
          adj[u].insert(v);
     }

     for(int i=1;i<=n;i++){
          if(!vis[i]){
               if(cycle(i)){
                    cout<<-1<<endl;
                    return;
               }
          }
     }
     for(int i=1;i<=n;i++){
          if(!vis[i]){
              dfs(i);
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