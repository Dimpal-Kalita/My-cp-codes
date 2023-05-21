/**
 * 
 * author: Dimpal Kalita
 * date: 16/05/2023 07:34:45
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
      ll n,x;
      cin>>n>>x;
      vl v(n);
      inp(v);
      ll ind=1, last=0;
      rep(i,0,n){
          if(ind==x-1){
               last=i+1;
               break;
          }
          if(ind>x-1){
               last=i;
               break;
          }
          ind+= v[i]+1;
      }

      for(int i=last;i<n;i++){
          if(v[i]==2){
               cout<<"No"<<endl;
               return;
          }
      }
      cout<<"Yes"<<endl;

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