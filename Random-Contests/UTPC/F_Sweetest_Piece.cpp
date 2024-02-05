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


vector<vl>dx={{1,0},{-1,0},{1,1},{-1,-1}};
void dk(){
     ll n,m,q;
     cin>>n>>m>>q;
     vector<vl>h(n,vl(m));
     rep(i,0,n){
          rep(j,0,m){
               cin>>h[i][j];
          }
     }
     vector<vl>v(n,vl(m)),vis(n,vl(m));

     function<void(ll,ll)>dfs=[&](ll x,ll y){
          if(x<0 or y<0 or x>=n or y>=m or vis[x][y]) return;
          vis[x][y]=1;
          v[x][y]++;
          for(auto i:dx){
               ll a=x+i[0],b=y+i[1];
               if(a<0 or b<0 or a>=n or b>=m or vis[a][b]) continue;
               if(h[a][b]>h[x][y]) continue;
               dfs(a,b);
          }
     };

     rep(i,0,q){
          ll x,y;
          cin>>x>>y;
          x--,y--;
          vis.assign(n,vl(m,0));
          dfs(x,y);
     }
     ll mx=0;
     pll ans={0,0};
     rep(i,0,n){
          rep(j,0,m){
               if(v[i][j]>mx){
                    mx=v[i][j];
                    ans={i,j};
               }
          }
     }
     cout<<ans.F+1<<" "<<ans.S+1<<" "<<mx<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   