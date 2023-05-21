/**
 * 
 * author: Dimpal Kalita
 * date: 26/04/2023 20:06:41
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
      ll x;
      cin>>x;
      if(x==1){
          cout<<-1<<endl;
          return;
      }
      if(x==2){
          cout<<1<<" "<<1<<" "<<1<<endl;
          return;
      }
      ll xx=1e6;
      if(x>xx){
          // cout<<1<<" ";
          if(x%xx==0){
               cout<<x/xx-1<<" "<<xx<<" "<<xx<<endl;
          }else{
               cout<<x/xx<<" "<<xx<<" "<<x%xx<<endl;
          }
          return;
      }

      ll val=sqrtl(x);
      while(val*val<x) val++;
      while(val*val>x) val--;
      if(val*val==x){
          cout<<val-1<<" "<<val<<" "<<val<<endl;
          return;
      }
      else{
          cout<<val<<" "<<val<<" "<<x-val*val<<endl;
          return;
      }
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