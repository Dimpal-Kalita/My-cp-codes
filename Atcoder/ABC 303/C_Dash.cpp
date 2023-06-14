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
     ll n,m,h,k;
     cin>>n>>m>>h>>k;
     pll start={0,0};
     string s;
     cin>>s;
     vector<pll> v(m);
     map<pll,ll> vis;
     while(m--){
          cin>>v[m].F>>v[m].S;
          vis[v[m]]=0;
     } 
     sort(all(v));
     

     for(auto it:s){
          if(it=='R'){
               start.F++;               
          }
          else if(it=='L'){
               start.F--;
          }
          else if(it=='U'){
               start.S++;
          }
          else if(it=='D'){
               start.S--;
          }
          h--;
          if(h<0){
               cout<<"No"<<endl;
               return;
          }
          if(h<k){
               if(binary_search(all(v),start) and !vis[start]){
                   h=k;
                   vis[start]=1;
               }
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