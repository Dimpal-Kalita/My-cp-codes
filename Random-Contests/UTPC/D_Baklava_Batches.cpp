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



ll getclosest(ll a,ll b,ll x){
     return abs(a-x)<abs(b-x)?a:b;
}

ll findclosest(vl &b,ll n,ll x){
     ll l=0,r=n-1;
     while(l<r){
          ll mid=(l+r)/2;
          if(b[mid]==x) return x;
          if(b[mid]<x) l=mid+1;
          else r=mid;
     }
     if(l==0 and l==n) return b[0];
     if(l==0) return getclosest(b[0],b[1],x);
     if(l==n) return getclosest(b[n-1],b[n-2],x);
     return getclosest(getclosest(b[l-1],b[l],x),getclosest(b[l],b[l+1],x),x);
}

void dk(){
     ll n;
     cin>>n;
     vl a(n),b(n);
     inp(a);
     inp(b);
     sort(all(b));
     ll ans=1e18;
     ll sum=accumulate(all(b),0LL);
     
     for(int i=0;i<n;i++){
         ans=min(ans,abs(findclosest(b,b.size(),a[i])-a[i]));
     }
     for(auto i:a){
          if(i<=sum){
               cout<<ans<<endl;
               return;
          }
     }

     cout<<"-1"<<endl;
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