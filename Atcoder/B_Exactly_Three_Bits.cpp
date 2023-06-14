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


ll calc(ll n){
     ll x=__builtin_popcountll(n);
     string t=bitset<64>(n).to_string();
     // cout<<t<<endl;
     for(ll i=0;i<64;i++){
          if(x==3) break;
          ll po= 1ll<<i;
          if((po&n)){
               n-=po;
               x--;
          }
     }
     // t=bitset<64>(n).to_string();
     // cout<<t<<" ";

     return n;
}


void dk(){
     ll n;
     cin>>n;
     ll x=__builtin_popcountll(n);
     if(x==3){
          cout<<n<<endl;
          return;
     }

     // cout<<x<<" ";
     if(x>3){
          cout<<calc(n)<<endl;
          return;
     }
     // x=__builtin_popcountll(n);
     for(int i=0;i<64;i++){
          ll po= 1ll<<i;
          if(x>=3 || ) break;
          if((po&n)==0){
               n-=po;
          }
          x=__builtin_popcountll(n);
     }
     if(x<3){
          cout<<-1<<endl;
          return;
     }
     cout<<calc(n)<<endl;

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