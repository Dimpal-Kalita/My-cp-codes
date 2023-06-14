/**
 * 
 * author: Dimpal Kalita
 * date: 26/05/2023 23:28:49
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









const int MAXN= 30;

vector<int> g[MAXN];
int par[MAXN];
int depth[MAXN];




void dfs(int v, int p, int d) {
  depth[v] = d;
  par[v] = p;
  for(int c: g[v])
    if(c != p) dfs(c, v, d + 1);
}



vector<int> getpath(int a, int b) {
  vector<int> ans, path1, path2;
  path1.push_back(a);
  path2.push_back(b);
  while(a != b) {
    if(depth[a] < depth[b]) path2.push_back(b = par[b]);
    else if(depth[a] > depth[b]) path1.push_back(a = par[a]);
    else if(depth[a] == depth[b]) path1.push_back(a = par[a]), path2.push_back(b = par[b]);
  }
  reverse(path2.begin(), path2.end());
  path2.erase(path2.begin());
  path1.insert(path1.end(), path2.begin(), path2.end());
  return ans = path1;
}

void dk(){
     ll n;
     cin>>n;
     rep(i,0,n-1){
          ll a,b;
          cin>>a>>b;
          g[a].pb(b);
          g[b].pb(a);
     }
     dfs(1,0,0);

     ll m;
     cin>>m;
     vector<pll> vp;
     rep(i,0,m){
          ll a,b;
          cin>>a>>b;
          vp.pb({a,b});
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