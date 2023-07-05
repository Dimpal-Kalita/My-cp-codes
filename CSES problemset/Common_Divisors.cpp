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
     int n;
     cin>>n;
     vl v(n),cnt(1e6+1,0);
     inp(v);
     rep(i,0,n){
          int x=v[i];
          for(int j=1;j*j<=x;j++){
               if(x%j==0){
                    cnt[j]++;
                    if(j*j!=x) cnt[x/j]++;
               }
          }
     }
     int ans=1;
     for(int i=1e6;i>=1;i--){
          if(cnt[i]>1){
               ans=i;
               break;
          }
     }
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