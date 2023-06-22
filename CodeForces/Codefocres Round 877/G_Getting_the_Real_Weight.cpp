/**
 * 
 * author: Dimpal Kalita
* 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
// #define endl                " \n"
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
     ll x;
     cin>>x;
     vector<ll> sq;
     for(ll i=0;i<=100005;i++){
         sq.pb(i*i);
     }
     
     vector<ll>dif,ans;
     ll sum=0;
     for(ll i=1;i<sq.size();i++){
         sum+= sq[i]-sq[i-1];
         dif.pb(sum);
     }
     ll n=dif.size(); 
     for(ll i=0,j=0;i<n;i++){
         while(j<i and dif[i]-dif[j]>x){
                j++;
         }

         if(dif[i]-dif[j]==x){
               ans.pb(i);
         }
     }
     if(ans.size()==0){
          cout<<0<<endl;
          return;
     }
     ll size=ans.size();
     cout<<size<<endl;
     for(ll i=0;i<size-1;i++){
         cout<<ans[i]+1<<" ";
     }
     cout<<ans[size-1]+1<<endl;
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