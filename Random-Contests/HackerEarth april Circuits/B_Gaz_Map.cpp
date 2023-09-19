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

lld pi=3.14159265358979323846;


void dk(){
     lld x1,x2,y1,y2;
     cin>>x1>>y1>>x2>>y2;


     cout<<fixed<<setprecision(7);
     if((x1==0 and x2==0) || (y1==0 and y2==0)){
          lld dist= sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
          cout<<dist<<endl;
          return;
     }
     x1=abs(x1),x2=abs(x2),y1=abs(y1),y2=abs(y2);
     if(x1==0 and y2==0){
         if(x2<y1){
               lld road= (pi*x2)/2;
               swap(x2,y2);
               lld dist= sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
               cout<<road+dist<<endl;
               return;
         }else{
               lld road= (pi*y1)/2;
               swap(x1,y1);
               lld dist= sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
               cout<<road+dist<<endl;
               return;
         }
     }
     if(x2==0 and y1==0){
         if(x1<y2){
               lld road= (pi*x1)/2;
               swap(x1,y1);
               lld dist= sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
               cout<<road+dist<<endl;
               return;
         }else{
               lld road= (pi*y2)/2;
               swap(x2,y2);
               lld dist= sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
               cout<<road+dist<<endl;
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