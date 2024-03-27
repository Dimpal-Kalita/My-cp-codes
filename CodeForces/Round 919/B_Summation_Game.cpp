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
     vl v(n);
     inp(v);
     sort(all(v),greater<ll>());
     ll ans=-1e9,sum=0,total=accumulate(all(v),0LL);
     ll ud=0;
     for(int i=0;i<min(x,n);i++){
          sum+=v[i];
     }
     ans=max(ans,total-2*sum); 
     for(int i=0;i<min(k,n);i++){
          sum-=v[i];
          total-=v[i];
          if(i+x<n) sum+=v[i+x];
          // cout<<sum<<" "<<total<<" "<<i<<endl;
          ans=max(ans,total-2*sum);
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