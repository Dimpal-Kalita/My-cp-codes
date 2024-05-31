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


vector<pll>dxy={{0,1},{1,0}};
void dk(){
     ll n,m;
     cin>>n>>m;
     vector<vl>v(n,vl(m));
     rep(i,0,n) inp(v[i]);
     vector<vl>vis(n,vl(m,-1));

     function<bool(ll,ll,ll)> dfs=[&](ll i,ll j,ll g)->bool{
          if(i==n-1 and j==m-1) return 1;
          if(vis[i][j]!=-1) return vis[i][j];
          for(auto [dx,dy]:dxy){
               ll x=i+dx,y=j+dy;
               if(x<n and y<m and v[x][y]%g==0 and dfs(x,y,g)) return vis[i][j]=1;
          }
          return vis[i][j]=0;
     };
     ll ans=1;
     for(ll i=1;i*i<=v[0][0];i++){
          ll x=i,y=v[0][0]/i;
          if(v[0][0]%x==0 and v[n-1][m-1]%x==0){
               vis.assign(n,vl(m,-1));
               if(dfs(0,0,x)) ans=max(ans,x);
          }
          if(v[0][0]%y==0 and v[n-1][m-1]%y==0 and dfs(0,0,y)){
               vis.assign(n,vl(m,-1));
               if(dfs(0,0,y))    ans=max(ans,y);
          }
     }
     for(ll i=1;i*i<=v[n-1][m-1];i++){
          ll x=i,y=v[n-1][m-1]/i;
          if(v[n-1][m-1]%x==0 and v[0][0]%x==0){
               vis.assign(n,vl(m,-1));
               if(dfs(0,0,x)) ans=max(ans,x);
          }
          if(v[n-1][m-1]%y==0 and v[0][0]%y==0){
               vis.assign(n,vl(m,-1));
               if(dfs(0,0,y)) ans=max(ans,y);
          }
     }
     cout<<ans<<endl;
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