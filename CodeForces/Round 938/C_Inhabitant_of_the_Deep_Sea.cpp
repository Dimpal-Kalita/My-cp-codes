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
     ll n,k;
     cin>>n>>k;
     vl v(n);
     inp(v); 
     ll cur=0,ans=0;
     ll x=k/2+k%2,y=k/2;
     for(int i=0;i<n;i++){
          ll mn=min(v[i],x);
          v[i]-=mn;
          x-=mn;
          if(x==0) break;
     }
     for(int i=n-1;i>=0;i--){
          ll mn=min(v[i],y);
          v[i]-=mn;
          y-=mn;
          if(y==0) break;
     }
     for(int i=0;i<n;i++){
          ans+=(v[i]==0);
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