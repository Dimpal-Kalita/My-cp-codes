/**
 * ProblemLink: https://saco-evaluator.org.za/cms/sapo2015z/tasks/jazz/description
 * author: Dimpal Kalita
 * date: 15/06/2023 13:02:34
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
vector<vl> dp(1001,vl(1001,-1));
ll recur(ll i, ll j){
     if(i>j) return 0;

     if(dp[i][j]!=-1) return dp[i][j];

     ll ans=recur(i+1,j)+1;

     for(int k=i+1;k<=j;k++){
          if(s[i]==s[k]){
               ans=min(ans,recur(i+1,k-1)+recur(k+1,j));
          }
     }
     // cout<<i<<" "<<j<<" "<<ans<<endl;
     return dp[i][j]=ans;
}

void dk(){
     cin>>s;
     cout<<recur(0,s.length()-1)<<endl;
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