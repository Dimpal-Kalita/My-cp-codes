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
      vector<vl>v;
      int n;
      cin>>n;

      rep(i,0,n){
          int k;
          cin>>k;
          vl temp(k);
          inp(temp);
          v.pb(temp);
      }
      ll x;
      cin>>x;
      ll last=39;
      vl ans;
      rep(i,0,n){
          rep(j,0,v[i].size()){
               if(v[i][j]==x){
                    last=min(last,(ll)v[i].size());
               }
          }
      }
     rep(i,0,n){
          rep(j,0,v[i].size()){
               if(v[i][j]==x and v[i].size()==last){
                    ans.pb(i+1);
               }
          }
      }     
      cout<<ans.size()<<endl;
      for(auto x:ans){
          cout<<x<<" ";
      }
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