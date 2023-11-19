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
     ll ans=0;
     for(int i=1;i*i<=n;i++){
          if(n%i!=0) continue;
          ll x=n/i;
          ll mx=0,mn=1e18;
          ll sum=0;
          ll ct=x;
          for(int j=0;j<n;j++){
               sum+=v[j];
               ct--;
               if(ct==0){
                    mx=max(mx,sum);
                    mn=min(mn,sum);
                    sum=0;
                    ct=x;
               }
          }
          if(x!=n) ans=max(ans,mx-mn);
          x=i;
          mx=0,mn=1e18;
          sum=0;
          ct=x;
          for(int j=0;j<n;j++){
               sum+=v[j];
               ct--;
               if(ct==0){
                    mx=max(mx,sum);
                    mn=min(mn,sum);
                    sum=0;
                    ct=x;
               }
          }
          ans=max(ans,mx-mn);
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