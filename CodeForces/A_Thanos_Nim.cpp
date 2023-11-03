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


vector<vl> dp(51,vl(51,-1));

ll recur(ll i,ll j){
     if(i==0 and j==0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     bool flag=1;
     for(ll k=1;k<=50;k++){
          if(i-k>=0) flag&=recur(i-k,j);
          if(j-k>=0) flag&=recur(i,j-k);
     }
     return dp[i][j]=flag^1;
}

void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     recur(50,50);
     sort(all(v));
     for(int i=0;i<50;i++){
          for(int j=0;j<50;j++){
               cout<<dp[i][j]<<" ";
          }
          cout<<endl;
     }
     cout<<dp[0][v[n/2]]<<endl;
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