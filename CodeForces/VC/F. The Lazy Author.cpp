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
     ll n,k;
     cin>>n>>k;
     vector<ll>v(n+1);
     rep(i,0,n){
         cin>>v[i];
     }

     vector<ll>flip(n+1,0);

     ll ct=0;
     vector<ll>ans;
     for(int i=0;i<n-k;i++){
         ct-=flip[i];

         if(v[i]==0 and ct%2==0){
             ct++;
             flip[i+k]++;
             ans.pb(i+1);
         }
         if(v[i]==1 and ct%2==1){
             ct++;
             flip[i+k]++;
             ans.pb(i+1);
         }
     }

     ll zero=0;
     for(int i=n-k;i<n;i++){
         ct-=flip[i];
         if(v[i]==0 and ct%2==0) zero++;
         if(v[i]==1 and ct%2==1) zero++;
     }
     cerr<<zero<<endl;
     if(zero>k/2) ans.pb(n-k+1);
     cout<<ans.size()<<endl;
     for(auto &it:ans){
         cout<<it<<" ";
     }


}



int main()
{ 
    fast_io;
  
    int n=1;
    //cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}
