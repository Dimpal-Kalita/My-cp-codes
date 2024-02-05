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
     vl vp=v;
     sort(all(v));

     vl ps(n);
     ps[0]=v[0];
     for(int i=1;i<n;i++){
          ps[i]=ps[i-1]+v[i];
     }
     
     for(auto i:vp){
          ll x=i;
          ll ans=0;
          while(ans<n-1){
               ll ind=upper_bound(all(v),x)-v.begin();
               if(ind==n || v[ind]>x) ind--;
               if(x==ps[ind]) break;
               x=ps[ind];
               ans=max(ans,ind);
          }
          cout<<ans<<" ";
     }
     cout<<endl;
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