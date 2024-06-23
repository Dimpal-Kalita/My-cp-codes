#include<bits/stdc++.h>
using namespace std;

#define md                  3000000007
#define pb                  push_back
#define endl                "\n"
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
     ll n;
     cin>>n;
     ll l=1e9+2,r=0;
     ll costl=1e9+2,costr=1e9+2,costlr=1e9+2;
     for(int i=0;i<n;i++){
          ll x,y,c;
          cin>>x>>y>>c;
          if(x<=l and y>=r){
               if(x==l and y==r) costlr=min(costlr,c);
               else costlr=c;
               if(x==l){
                    costl=min(costl,c);
               }
               if(y==r){
                    costr=min(costr,c);
               }
               if(x<l){
                    costl=c;
               }
               if(y>r){
                    costr=c;
               }
               l=x;
               r=y;
          }else{
               if(x<l){
                    costl=c;
                    l=x;
                    costlr=md;
               }
               if(y>r){
                    costr=c;
                    costlr=md;
                    r=y;
               }
               if(x==l){
                    costl=min(costl,c);
               }
               if(y==r){
                    costr=min(costr,c);
               }
          }
          cout<<min(costl+costr,costlr)<<endl;
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