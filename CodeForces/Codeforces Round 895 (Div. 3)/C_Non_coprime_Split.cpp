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
     ll l,r;
     cin>>l>>r;
     if(r<=3){
          cout<<"-1"<<endl;
          return;
     }
     if(l!=r){
          if(r%2==0){
               cout<<r/2<<" "<<r/2<<endl;
          }else{
               cout<<(r-1)/2<<" "<<(r-1)/2<<endl;
          }
          return;
     }
     if(l==r and l%2==0){
          cout<<l/2<<" "<<r/2<<endl;
          return;
     }
     ll x=l;
     for(int i=2;i*i<=x;i++){
          if(x%i==0){
               ll a=(x-i)/2;
               ll b=(x-a);
               if(gcd(a,b)>1 and a>0 and b>0){
                    cout<<a<<" "<<b<<endl;
                    return;
               }
               a=(x-(x/i))/2;
               b=(x-a);
               if(gcd(a,b)>1 and a>0 and b>0){
                    cout<<a<<" "<<b<<endl;
                    return;
               }
          }
     }
     cout<<"-1"<<endl;
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