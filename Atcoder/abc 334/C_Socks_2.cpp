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
     ll m,n;
     cin>>m>>n;
     vl v(n);
     inp(v);
     sort(all(v));
     vector<ll>ps(n+3);
     ll sum=0;
     for(int i=1;i<n;i+=2){
          sum+=v[i]-v[i-1];
          ps[i]=sum;
     }
     vl ss(n+3);
     sum=0;
     for(int i=n-2;i>=0;i-=2){
          sum+=v[i+1]-v[i];
          ss[i]=sum;
     }
     if(n%2==0){
          cout<<ps[n-1]<<endl;
          return;
     }
     ll ans=ps[n-2];
     for(int i=0;i<n;i++){
          if(i%2==0){
               ll x=(i-1>=0?ps[i-1]:0);
               ll y=(i+1<n?ss[i+1]:0);
               // cout<<x<<" "<<y<<endl;
               ans=min(ans,x+y);
          }
     }
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   