/**
 * 
 * author: Dimpal Kalita
 * date: 30/04/2023 10:55:51
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

const int MAX=100;
vector<vector<vl>> dp(100, vector<vl>(100,vl(2,-1)));
ll n, m, k, d;

ll recur(ll c, ll x=0, ll y=0, ll z=0){
     if(dp[x][y][z]!=-1) return dp[x][y][z];

     dp[x][y][z]= (y==k);

     if(x==to_string(c).length()){
          return dp[x][y][z];
     }
     ll limit=9;
     if(!z){
          limit= to_string(c)[x]-'0';
     }

     dp[x][y][z]=0;

     rep(xth_digit,0,limit+1){
          if(z) dp[x][y][z]+=recur(c, x+1, y+(xth_digit==d),1);
          else dp[x][y][z]+=recur(c,x+1,y+(xth_digit==d),xth_digit<limit);
     }

     return dp[x][y][z];
}

void dk(){
      cin>>m>>k>>d;
      int total= recur(m);
      cout<<total<<endl;
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