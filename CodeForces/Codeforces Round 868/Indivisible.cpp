/**
 * 
 * author: Dimpal Kalita
 * date: 29/04/2023 20:22:26
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


void dk(){
      ll n;
      cin>>n;
      if(n==1){
          cout<<1<<endl;
          return;
      }
      if(n%2){
          cout<<-1<<endl;
          return;
      }
      vl ans(n);
      ll x=2, y=1;
      for(int i=0;i<n;i++){
          if(i%2){
               ans[i]= y;
               y+=2;
          }else{
               ans[i]= x;
               x+=2;
          }
      }

      for(auto it:ans){
          cout<<it<<" ";
      }
      cout<<endl;

}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}