/**
 * 
 * author: Dimpal Kalita
 * date: 30/04/2023 11:39:02
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


vector<vector<vl>> dp(100,vector<vl>(200,vl (2,-1)));

void reset(){
     dp.clear();
     dp.resize(100, vector<vl>(200,vl(2,-1)));
}


ll a, b;

ll recur(ll c, ll x=0,ll y=0,bool z=0){
     
     if(dp[x][y][z]!=-1) return dp[x][y][z];

     if(x==to_string(c).length()){
          return 0;
     }

     ll limit=9;
     if(!z){
          limit= to_string(c)[x]-'0';
     }
     ll val=0;
     for(int i=0;i<=limit;i++){
          val+= (z?recur(c,x+1,y+i,1):recur(c,x+1,y+i,i<limit));
          if(i!=0) val+= y+i;
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
     //  cout<<y<<" "<<x<<" /";
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