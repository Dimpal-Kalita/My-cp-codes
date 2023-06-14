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

ll n,x,y,z;
string s;
vector<vl>dp(300010,vl(2,-1));

ll recur(ll ind, bool caps=0){
     if(ind==n) return 0;
     if(dp[ind][caps]!=-1) return dp[ind][caps];     
     ll ans=1e18;
     if(s[ind]=='A'){
        if(caps){
            ans = min(ans, x+ recur(ind+1 , 1));
            ans = min(ans, y+z+ recur(ind+1 , 0));
        }else{
            ans = min(ans, x+z+recur(ind+1 , 1));
            ans = min(ans,  y+recur(ind+1 , 0));
        }
     }
     else{
          if(caps){
               ans=min(ans,y+recur(ind+1 , 1));
               ans=min(ans,x+z+recur(ind+1 , 0));
          }
          else{
               ans=min(ans,x+recur(ind+1 , 0));
               ans=min(ans,y+z+recur(ind+1 , 1));
          }
     }

     return dp[ind][caps]=ans;
}


void dk(){ 
     cin>>x>>y>>z;
     cin>>s;
     n=s.length();
     cout<<recur(0)<<endl;
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