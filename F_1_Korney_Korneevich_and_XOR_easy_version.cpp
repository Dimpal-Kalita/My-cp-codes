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


int n;
vi v;
set<int>ans;
vi dp(600,INT_MIN);

void dk(){
     cin>>n;
     v=vi(n,0);
     inp(v);

     for(int i=0;i<n;i++){
          for(int j=0;j<600;j++){
               if(j>v[i])
                    dp[j^v[i]]=max(dp[j^v[i]],v[i]);
          }
     }

     rep(i,0,501){
          if(dp[i]>=0){
               ans.insert(i);
          }
     }

     for(auto it:ans){
          cout<<it<<" ";
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