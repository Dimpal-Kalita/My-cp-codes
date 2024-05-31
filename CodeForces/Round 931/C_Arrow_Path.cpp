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


vector<pll>dir={{0,1},{1,0},{0,-1},{-1,0}};
void dk(){
     ll n;
     cin>>n;
     vector<vector<ll>> vis(2,vector<ll>(n+1,0)); 
     vector<string> s(2);
     cin>>s[0]>>s[1];
     queue<pair<ll,ll>> q;
     q.push({0,0});
     while(!q.empty()){
          int x=q.front().F;
          int y=q.front().S;
          q.pop();
          if(x==1 and y==n-1){
               cout<<"YES"<<endl;
               return;
          }
          if(vis[x][y]) continue;
          vis[x][y]=1;
          for(auto d:dir){
               int nx=x+d.F;
               int ny=y+d.S;
               if(nx<0 or nx>1 or ny<0 or ny>=n) continue;
               if(vis[nx][ny]) continue;
               if(s[nx][ny]=='<'){
                    ny--;
               }
               else if(s[nx][ny]=='>'){
                    ny++;
               }
               q.push({nx,ny});
          }
     }
     cout<<"NO"<<endl;
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