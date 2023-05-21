/**
 * 
 * author: Dimpal Kalita
 * date: 19/05/2023 01:35:28
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
      ll l, r, m;
      cin>>l>>r>>m;

      for(int a=l;a<=r;a++){
          ll n= m/a;
          ll rem= m- n*a;
          // cout<<rem<<" /";
          if(rem<=r-l and n>0){
              cout<<a<<" "<<l+rem<<" "<<l<<endl;
              return;
          }
          rem= (n+1)*a-m;
          if(rem<=r-l and n+1>0){
              cout<<a<<" "<<l<<" "<<l+rem<<endl;
              return;
          }
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