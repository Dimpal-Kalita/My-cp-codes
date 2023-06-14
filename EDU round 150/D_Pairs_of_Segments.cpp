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




vector<pll>v;
vector<vector<vector<ll>>>dp;
ll recur(ll ind, ll last=-1, ll flag=0){
     if(ind==v.size()){
          if(!flag) return 0;
          return md;
     }
     // cout<<ind<<" "<<last<<endl;
     if(dp[ind][last+1][flag]!=-1) return dp[ind][last+1][flag];

     ll ans=1+recur(ind+1, last, flag);
     if(!flag){
          if(last==-1){
               ans=min(ans, recur(ind+1, ind, 1));
          }
          else if(v[ind].F>v[last].S){
               ll next= (v[ind].S>v[last].S)?ind:last;
               ans=min(ans, recur(ind+1, next, 1));
          }
     }else{
          if(v[ind].F<=v[last].S){
               ll next=(v[ind].S>v[last].S)?ind:last;
               ans=min(ans, recur(ind+1, next, 0));
          }
     }

     return dp[ind][last+1][flag]=ans;
}



void dk(){
     ll n;
     cin>>n;
     v.resize(n);
     dp.assign(n+1, vector<vector<ll>>(n+2, vector<ll>(2, -1)));
     for(int i=0;i<n;i++){
          cin>>v[i].F>>v[i].S;
     }
     sort(all(v));
     ll ans=recur(0);
     cout<<ans<<endl;
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