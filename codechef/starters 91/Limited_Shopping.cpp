/**
 * 
 * author: Dimpal Kalita
 * date: 24/05/2023 21:52:06
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

const int N=505;
vector<ll> v;
vector<vector<vl>> dp(N,vector<vl>(N,vl(N,-1)));

ll n,k;
ll recur(ll ind, ll k,ll prev){
     // cout<<k<<" ";
     if(ind==n || k==0){
          return 0;
     }
     if(dp[ind][k][prev]!=-1){
          return dp[ind][k][prev];
     }
     ll ans=0;
     for(int i=0;i<=min(k,prev+1);i++){
          // cout<<v[ind]*i<<" ";
          ans=max(ans,v[ind]*i+recur(ind+1,k-i,i));
     }
     return dp[ind][k][prev]=ans;
}

void dk(){
     cin>>n>>k;
     v.resize(n);
     inp(v);
     cout<<max(recur(1,k,0),recur(1,k-1,1)*v[0])<<endl;
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