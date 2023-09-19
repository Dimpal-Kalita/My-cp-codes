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




string s;
vector<vector<pii>>dp;
pair<ll,ll> recur(ll i, ll j){
     if(i>j) return {true,0};
     if(i==j) return {1,1};

     if(dp[i][j] != make_pair(-1,-1)) return dp[i][j];

     ll ans=0;
     pll left=recur(i+1,j);
     pll right=recur(i,j-1);
     pll mid=recur(i+1,j-1);
     ans=left.S+right.S-mid.S;

     ll ret= mid.F&&(s[i]==s[j]);
     // cout<<i<<" "<<j<<" "<<ret<<endl;
     return dp[i][j]={ret,ans+ret};
}



void dk(){
     cin>>s;
     ll n;
     cin>>n;
     dp.resize(s.size(),vector<pii>(s.size(),{-1,-1}));
     while(n--){
          ll i,j;
          cin>>i>>j;
          i--,j--;
          cout<<recur(i,j).S<<endl;
     }
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