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



typedef struct Edge{
     ll source;
     ll target;
} edge;

map<edge,int>mp;
vector<vl>adj;

bool dfs(ll s, ll t,ll par){
     if(s==t) return 1;
     for(auto child:adj[s]){
          if(child==par) continue;
          if(dfs(child,t,s)){
               mp[{s,child}]++;
               return 1;
          }
     } 
     return 0;
}


void dk(){
     
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