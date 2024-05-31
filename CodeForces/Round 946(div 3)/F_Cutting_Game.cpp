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


#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll a,b,n,m;
     cin>>a>>b>>n>>m;
     set<pll>hor,ver;
     rep(i,0,n){
          ll u,v;
          cin>>u>>v;
          ver.insert({u,v});
          hor.insert({v,u});
     }      
     debug(ver);
     debug(hor);
     ll left=0,right=b+1, up=a+1,down=0;
     ll alice=0,bob=0;
     rep(i,0,m){
          char ch;
          cin>>ch;
          ll k;
          cin>>k;
          if(ch=='D'){
               up-=k;
               while(!ver.empty() and ver.rbegin()->F>=up){
                    if(i%2==0) alice++;
                    else bob++; 
                    auto it=hor.find({ver.rbegin()->S,ver.rbegin()->F});
                    hor.erase(it);
                    ver.erase(*ver.rbegin());
               }
          }else if(ch=='U'){
               down+=k;
               while(!ver.empty() and ver.begin()->F<=down){
                    if(i%2==0) alice++;
                    else bob++; 
                    auto it=hor.find({ver.begin()->S,ver.begin()->F});
                    hor.erase(it);
                    ver.erase(*ver.begin());
               }
          }else if(ch=='L'){
               left+=k;
               while(!hor.empty() and hor.begin()->F<=left){
                    if(i%2==0) alice++;
                    else bob++; 
                    auto it=ver.find({hor.begin()->S,hor.begin()->F});
                    ver.erase(it);
                    hor.erase(*hor.begin());
               }
          }else{
               right-=k;
               while(!hor.empty() and hor.rbegin()->F>=right){
                    if(i%2==0) alice++;
                    else bob++; 
                    auto it=ver.find({hor.rbegin()->S,hor.rbegin()->F});
                    ver.erase(it);
                    hor.erase(*hor.rbegin());
               }
          }
     }
     cout<<alice<<" "<<bob<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   