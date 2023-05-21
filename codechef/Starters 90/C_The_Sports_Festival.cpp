/**
 * 
 * author: Dimpal Kalita
 * date: 17/05/2023 18:08:25
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


const int N=2e3+7;
ll n;
vl v;
vector<vl> dp(N, vl(N,-1));


ll calc(ll l, ll r){
     if(r<=l || l>=n || r<0) return 0;
     if(dp[l][r]!=-1) return dp[l][r];
     return dp[l][r]=min(calc(l+1,r),calc(l,r-1))+ (v[r]-v[l]);

}

void dk(){
     cin>>n;
     v.resize(n);
     inp(v);
     sort(all(v));
     cout<<calc(0,n-1)<<endl;
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