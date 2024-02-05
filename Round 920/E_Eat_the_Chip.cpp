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
     ll h,w,xa,ya,xb,yb;
     cin>>h>>w>>ya>>xa>>yb>>xb;
     if(ya>=yb){
          cout<<"Draw"<<endl;
          return;
     }
     ll y=abs(yb-ya);
     if(y%2){
          ll left=max(1LL,xb-y/2);
          ll right=min(w,xb+y/2);
          if(abs(xa-left)-1<=y/2 and abs(xa-right)-1<=y/2){
               cout<<"Alice"<<endl;
          }else{
               cout<<"Draw"<<endl;
          }

     }else{
          ll left=max(1LL,xa-y/2);
          ll right=min(w,xa+y/2);
          if(abs(xb-left)<=y/2 and abs(xb-right)<=y/2){
               cout<<"Bob"<<endl;
          }else{
               cout<<"Draw"<<endl;
          }
     }
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