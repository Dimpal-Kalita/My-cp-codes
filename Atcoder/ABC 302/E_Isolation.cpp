/**
 * 
 * author: Dimpal Kalita
 * date: 20/05/2023 18:08:05
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
      set<ll> adj[n+1];
      map<ll,ll> mark;
      ll count=n;
      while(m--){
          ll q;
          cin>>q;
          if(q==1){
               ll u,v;
               cin>>u>>v;
               adj[u].insert(v);
               adj[v].insert(u);
               if(!mark[u]){
                    mark[u]=1;
                    count--;
               }
               if(!mark[v]){
                    mark[v]=1;
                    count--;
               }
               cout<<count<<endl;
          }
          else{
               ll v;
               cin>>v;
               for(auto x: adj[v]){
                    adj[x].erase(v);
                    if(!adj[x].size() and mark[x]){
                         mark[x]=0;
                         count++;
                    }  
               }
               adj[v].clear();
               if(mark[v]){
                    mark[v]=0;
                    count++;
               }
               cout<<count<<endl;
          }
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