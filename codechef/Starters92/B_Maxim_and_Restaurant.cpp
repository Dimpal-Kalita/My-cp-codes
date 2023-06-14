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


lld n,p;
vector<lld> v,fact(60);
vector<vector<vector<lld>>>dp(60,vector<vector<lld>>(60,vector<lld>(60,-1)));

lld recur(ll ind, ll k, ll take=0){
     if(ind>=n){
          if(take==0) return 0;
          else return fact[take]*fact[n-take];
     }

     if(dp[ind][k][take]!=-1) return dp[ind][k][take];
     lld ans=recur(ind+1,k,take);
     if(k-v[ind]>=0){
          ans+= recur(ind+1,k-v[ind],take+1);
     }
     return dp[ind][k][take]=ans;
}



void dk(){
     cin>>n;
     v.resize(n);
     inp(v);
     cin>>p;      
     sort(all(v));
     fact[0]=1;
     for(int i=1;i<=50;i++){
          fact[i]=(fact[i-1]*i);
     }
     lld ans=recur(0,p);
     cout<<(ans/fact[n])<<endl;
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