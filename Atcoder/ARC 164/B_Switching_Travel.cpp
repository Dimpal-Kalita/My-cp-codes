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


ll n,m;
vector<vl>adj;
vl par,col;
void dfs(ll node, ll parent){
     par[node]=parent;
     for(auto x: adj[node]){
          if(!par[x] and col[node]!=col[x]){
               dfs(x,parent);
          }
     }
}


void dk(){
     cin>>n>>m;
     adj.resize(n+1);
     par.resize(n+1);
     col.resize(n+1);
     rep(i,0,m){
          ll x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
     }
     rep(i,1,n+1){
          cin>>col[i];
     }
     rep(i,1,n+1){
          if(!par[i]){
               dfs(i,i);
          }
     }

     rep(i,1,n+1){
          for(auto x: adj[i]){
               if(par[i]==par[x] and col[i]==col[x]){
                    cout<<"Yes"<<endl;
                    return;
               }
          }
     }
     cout<<"No"<<endl;
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