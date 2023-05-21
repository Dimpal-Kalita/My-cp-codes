/**
 * 
 * author: Dimpal Kalita
 * date: 04/05/2023 20:10:14
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




vector<vector<vl>>dp;


void reset(){
     dp.clear();
     dp.resize(20, vector<vl>(20, vector<ll>(2,-1)));
}

ll recur(ll number, ll x=0, ll y=0, ll z=0){
     if(x==to_string(number).length()) return (y<=3?1:0);
     if(dp[x][y][z]!=-1) return dp[x][y][z];

     ll limit=9;
     if(!z){
         limit=to_string(number)[x]-'0';
     }

     ll val=0;
     rep(i,0,limit+1){
         val+=recur(number,x+1,y+(i!=0),(z?z:i<limit));
     }
     return dp[x][y][z]=val;
}


void dk(){
      ll a,b;
      cin>>a>>b;
      reset();
      ll x= recur(a-1);
      reset();
      ll y= recur(b);
      cout<<y-x<<endl;
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