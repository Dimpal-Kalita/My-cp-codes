/**
 * 
 * author: Dimpal Kalita
 * date: 06/05/2023 23:25:38
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




void dk(){
      ll n,m;
      cin>>n>>m;
      vector<vl> adj(n+1);
      vector<ll> degree(n+1);
      rep(i,0,m){
          ll x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
          degree[x]++;
          degree[y]++;
      }

      for(int i=1;i<=n;i++){
          bool flag=1;
          for(auto it:adj[i]){
               if(degree[it]!=degree[adj[i][0]]){
                    flag=0;
                    break;
               }
          }

          if(flag==1 and adj[i].size()>1 and degree[adj[i][0]]>1){
               cout<<adj[i].size()<<" "<<degree[adj[i][0]]-1<<endl;
               return;
          }
      }
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