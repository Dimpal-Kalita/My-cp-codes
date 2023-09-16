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
     string a,b;
     cin>>a>>b;
     vl blocks;
     int ct=0;
     for(int i=0;i<n;i++){
          if(a[i]==b[i]){
               if(ct) blocks.pb(ct);
               ct=0;
          }
          else{
               ct++;
          }
     }
     if(ct){
          blocks.pb(ct);
     }
     if(blocks.size()>2){
          cout<<0<<endl;
          return;
     }
     if(blocks.size()==1){
          cout<<2*(blocks[0]-1)<<endl;
          return;
     }
     int zero=0,prev=0;
     for(int i=0;i<n;i++){
          if(a[i]==b[i]) zero++;
          else{
               prev=zero;
               zero=0;
          }
     }
     cout<<(prev+2)*2<<endl;
}



int main()
{ 
    fast_io;
  
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}