/**
 * 
 * author: Dimpal Kalita
 * date: 21/10/2023 22:10:43
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

// hash for unordered set
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * md;
        x = (x ^ (x >> 27)) * md;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void dk(){
     ll n,m;
     cin>>n>>m;
     vector<string>v(n);

     for(auto &i:v) cin>>i;
     vector<vl>dp(n,vl(m,0));

     vector<pll>dxy={{1,0},{0,1},{-1,0},{0,-1}};
     set<pll>st;
     ll xx=-1,yy=-1;
     ll ct=0;
     function<ll(ll,ll)> dfs=[&](ll i,ll j)->ll{
          if(dp[i][j]) return dp[i][j];
          dp[i][j]=1;
          for(auto [dx,dy]:dxy){
               ll x=i+dx,y=j+dy;
               if(x>=0 and x<n and y>=0 and y<m){
                    if(v[x][y]=='.'){
                         st.insert({x,y});
                         xx=x,yy=y;
                    }
                    if(v[x][y]=='W' and dp[x][y]==0) dp[i][j]+=dfs(x,y);
               }
          }
          return dp[i][j];
     };
     vector<vl>cnt(n,vl(m,0));
     bool flag=0;
     rep(i,0,n){
          rep(j,0,m){
               if(dp[i][j] || v[i][j]!='W') continue;
               st.clear();
               dfs(i,j);
               if(sz(st)==1){
                    cnt[xx][yy]+=dp[i][j];
                    flag=1;
               }
          }
     }

     ll mx=0;
     rep(i,0,n){
          rep(j,0,m){
               mx=max(mx,cnt[i][j]);
          }
     }
     cout<<mx<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
     cout<<"Case #"<<i+1<<": ";
    dk();
   }
  return 0;
}