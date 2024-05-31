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
     ll n;
     cin>>n;
     ll l=n,r=n;
     vector<pll>ans;
     for(int i=0;i<2*n;i++){
          if(i%2){
               ans.pb({1,r--});
          }else{
               ans.pb({2,l--});
          }
     }
     ll sum=0;
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               sum+=max(i,j)+1;
          }
     }
     cout<<sum<<" "<<sz(ans)<<"\n";
     for(auto x: ans){
          cout<<x.F<<" "<<x.S<<" ";
          rep(i,1,n+1){
               cout<<i<<" ";
          }
          cout<<"\n";
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