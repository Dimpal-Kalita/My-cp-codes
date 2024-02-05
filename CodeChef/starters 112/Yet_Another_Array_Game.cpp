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
     vector<ll>v(n);
     inp(v);
     sort(all(v));
     ll ans=0;
     for(int i=0,j=n-1;i<=j;i++,j--){
          if(i==j-1){
               ans+=v[i]+v[j];
               ans-=v[0];     
               continue;
          }
          ans+=v[i];
     } 
     cout<<ans<<endl;
}

void dk1(){
     ll n;
     cin>>n;
     vector<ll>v(n);
     inp(v);
     sort(all(v));
     vector<ll>ps(n+1);
     for(int i=1;i<=n;i++) ps[i]=ps[i-1]+v[i-1];
     ll ans=0;
     for(int i=n-1,x=1;i-x+1>=0;i--,x++){
          ans=max(ans,ps[i+1]-ps[i-x+1]);
     }
     cout<<ans<<endl;
}


int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    ll s;
    cin>>s;
    for(int i=0;i<_;i++){
     if(s==0) dk();
     else dk1();
   }
  return 0;
}   