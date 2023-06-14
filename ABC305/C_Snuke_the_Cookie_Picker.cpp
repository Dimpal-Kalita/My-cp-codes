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


void dk(){
     ll n,m;
     cin>>n>>m;
     string s[n];
     rep(i,0,n) cin>>s[i];

     ll mxrow=0, mxcol=0;
     rep(i,0,n){
          ll cnt=0;
          rep(j,0,m){
               if(s[i][j]=='#') cnt++;
          }
          mxrow=max(mxrow,cnt);
     }
     rep(i,0,m){
          ll cnt=0;
          rep(j,0,n){
               if(s[j][i]=='#') cnt++;
          }
          mxcol=max(mxcol,cnt);
     }
     // cout<<mxrow<<" "<<mxcol<<endl;
     pll ans={0,0};
     rep(i,0,n){
          ll cnt=0;
          rep(j,0,m){
               if(s[i][j]=='#') cnt++;
          }
          // cout<<i<<" "<<cnt<<endl;
          if(cnt==mxrow-1){
               ans.F=i;
          }
     }
     rep(i,0,m){
          ll cnt=0;
          rep(j,0,n){
               if(s[j][i]=='#') cnt++;
          }
          if(cnt==mxcol-1){
               ans.S=i;
          }
     }

     cout<<ans.F+1<<" "<<ans.S+1<<endl;
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