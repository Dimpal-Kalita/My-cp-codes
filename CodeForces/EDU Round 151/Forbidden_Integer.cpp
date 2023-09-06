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
     ll n,k,x;
     cin>>n>>k>>x;
     if(x!=1){
          cout<<"YES"<<endl;
          cout<<n<<endl;
          rep(i,0,n){
               cout<<1<<" ";
          }
          cout<<endl;
          return;
     }
     if(n>=2){
          if(n%2==0 and k>=2){
               cout<<"YES"<<endl;
               cout<<n/2<<endl;
               rep(i,0,n/2){
                    cout<<2<<" ";
               }
               cout<<endl;
               return;
          }
          else if(n%2==1 and k>=3){
               cout<<"YES"<<endl;
               ll ct=1;
               n-=3;
               cout<<n/2+1<<endl;
               cout<<3<<" ";
               rep(i,0,n/2){
                    cout<<2<<" ";
               }
               cout<<endl;
               return;
          }
          else{
               cout<<"NO"<<endl;
               return;
          }
          return;
     }
     else{
          cout<<"NO"<<endl;
          return;
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