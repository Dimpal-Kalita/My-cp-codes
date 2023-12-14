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
     vl v(n);
     inp(v);
  
     ll last=0,ans=-1e10,sum=0;
     for(int i=0;i<n;i++){
          sum+=v[i];

          if(v[i]!=v[last]){
               ans=max(ans,sum);
          }

          if(sum<0){
               last=i+1;
               sum=0;
          }

     }
     last=n-1,sum=0;
     for(int i=n-1;i>=0;i--){
          sum+=v[i];

          if(v[i]!=v[last]){
               ans=max(ans,sum);
          }

          if(sum<0){
               last=i-1;
               sum=0;
          }

     }
     
     for(int i=0;i<n-1;i++){
         if(v[i]!=v[i+1]) ans=max(ans,v[i]+v[i+1]);
     }
     if(ans<(-3e9)){
          cout<<"Not Possible"<<endl;
          return;
     }
     cout<<ans<<endl;
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