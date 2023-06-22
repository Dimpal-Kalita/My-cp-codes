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

ll n,m,k;
vl v;
vector<vl> dp(5505, vl(5505,-1));

ll recur(ll ind, ll val){
     if(val==k) return 0;
     
     if(ind+m>n) return -1e14;
     if(dp[ind][val]!=-1) return dp[ind][val];

     ll ans=0;
     ll np=recur(ind+1,val);
     for(int i=ind;i<ind+m;i++){
          ans+=v[i];
     }
     ll p=ans+recur(ind+m,val+1);
     // cout<<ind<<" "<<val<<" "<<p<<" "<<np<<endl;
     return dp[ind][val]=max(p,np);
}


void dk(){
     cin>>n>>m>>k;
     v.resize(n);
     inp(v);
     cout<<recur(0,0)<<endl;
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