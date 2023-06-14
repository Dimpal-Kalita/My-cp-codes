/**
 * 
 * author: Dimpal Kalita
 * date: 26/05/2023 17:59:35
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
vector<vl>dp;
ll recur(ll ind, bool neg=0){
     if(ind==s.length()){
          if(!neg) return 0;
          return 1;
     }
     if(dp[ind][neg]!=-1) return dp[ind][neg];
     ll ans=1e9;
     if(s[ind]=='1'){
          if(neg) ans=min(ans,recur(ind+1,neg));
          else {
               ans= min(ans,recur(ind+1,0)+1);
               ans=min(ans,recur(ind+1,1)+1);
          }
     }
     else{
          if(!neg) ans=min(ans,recur(ind+1,neg));
          else{
               ans=min(ans,recur(ind+1,0)+1);
               ans=min(ans,recur(ind+1,1)+1);
          }
     }
     return dp[ind][neg]=ans;
}


void dk(){
      cin>>s;
      dp.resize(s.length()+1,vl(2,-1));
      ll ans=recur(0);
      cout<<ans<<endl;
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