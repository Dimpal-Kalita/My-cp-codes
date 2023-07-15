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
vector<vi>adj;
vi dp,vis;

int dfS(int node){
     if(vis[node]) return dp[node];
     vis[node]=1;
     if(node==n) return dp[node]=1;
     for(auto x: adj[node]){
          dp[node]+=dfS(x);
          dp[node]%=md;
     }
     return dp[node];
}

void dk(){
     cin>>n>>m; 
     adj=vector<vi>(n+1);
     dp=vi(n+1,0);
     vis=vi(n+1,0);
     for(int i=0;i<m;i++){
          int x,y;
          cin>>x>>y;
          adj[x].pb(y);
     }
     cout<<dfS(1)<<endl;
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