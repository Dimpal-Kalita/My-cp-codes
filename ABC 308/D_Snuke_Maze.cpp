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

ll n, m;
vector<string>v;
vector<vl>vis;
map<char,char>mp;
vector<pll> dxy={{-1,0},{0,-1},{1,0},{0,1}};

bool dfs(ll x, ll y){
     if(x==n-1 and y==m-1) return 1;
     if(vis[x][y]!=-1) return vis[x][y];
     vis[x][y]=0;
     bool ans=0;
     for(auto [dx,dy]:dxy){
          if(x+dx<0 || x+dx>=n || y+dy<0 || y+dy>=m) continue;
          if(mp[v[x][y]]==v[x+dx][y+dy]) ans|=dfs(x+dx,y+dy);
     }
     return vis[x][y]=ans;
}

void dk(){
      cin>>n>>m;
      mp['s']='n',mp['n']='u',mp['u']='k',mp['k']='e',mp['e']='s';
      v.resize(n);
      vis.resize(n+1,vl(m+1,-1));
      inp(v);
      cout<<(dfs(0,0)?"Yes":"No")<<endl;
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