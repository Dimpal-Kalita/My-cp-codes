/**
 * 
 * author: Dimpal Kalita
 * date: 21/05/2023 22:12:32
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


// answer will be number of connected components formed by 0 edges -1
// that is we will be needing count-1  1 weight edges to form the graph
// so we travel try to travel through 0 weight edges of the graph
// we will be travelling for n times only
// https://codeforces.com/blog/entry/93652

void dk(){
      ll n,m;
      cin>>n>>m;
      vector<set<ll>>adj(n+1);
      rep(i,0,m){
          ll u,v;
          cin>>u>>v;
          adj[u].insert(v);
          adj[v].insert(u);
      }
      set<ll> st;
      rep(i,1,n+1) st.insert(i);
      

      int count=0;
      while(!st.empty()){
          count++;
          queue<ll> q;
          q.push(*st.begin());
          st.erase(st.begin());
          while(!q.empty()){
              ll u=q.front();
              q.pop();
              vector<ll> v;

              for(auto x:st){
                  if(!adj[u].count(x)){
                      v.pb(x);
                  }
              }

              for(auto x:v){
                  st.erase(x);
                  q.push(x);
              }
          }
      }
      cout<<count-1<<endl;
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