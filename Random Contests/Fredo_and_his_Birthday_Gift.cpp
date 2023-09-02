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


void dk(){
     int n,m;
     cin>>n>>m;
     vector<vi>adj(n+1,vi(n+1,0));
     rep(i,0,m){
          int x,y;
          cin>>x>>y;
          adj[x][y]=1;
          adj[y][x]=1;
     }
     vector<vector<int>>dp(n+1,vector<int>(1<<(n+1),0));
     for(int i=1;i<=n;i++){
          dp[i][1<<i]=i;
     }
     for(int i=0;i<(1<<(n+1));i++){
          for(int j=1;j<=n;j++){
               if(i&(1<<j)){
                    for(int k=1;k<=n;k++){
                         if(i&(1<<k) and k!=j and adj[k][j]){
                              dp[j][i]=max(dp[j][i],dp[k][i^(1<<j)]+k);
                         }
                    }
               }
          }
     }

     vector<int>v;
     for(int i=1;i<=n;i++){
          int val=dp[i][(1<<(n+1))-1];
          if(val==0) val=i;
          v.pb(val);
          cout<<val<<" ";
     }
     sort(all(v));
     int a=v[0],b=v[n-1];
     int x=b/__gcd(a,b);
     int y=a/__gcd(a,b);
     cout<<x<<" "<<y<<endl;
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