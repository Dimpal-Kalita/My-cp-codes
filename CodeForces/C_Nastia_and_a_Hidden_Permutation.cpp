#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
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


ll n;

ll one(ll i,ll j){
     cout<<"? "<<1<<" "<<i<<" "<<j<<" "<<n-1<<endl;
     ll x;
     cin>>x;
     return x;
}

ll two(ll i,ll j){
     cout<<"? "<<2<<" "<<i<<" "<<j<<" "<<1<<endl;
     ll x;
     cin>>x;
     return x;
}    


void dk(){
     cin>>n;
     vector<ll>ans(n+1);
     ll ind=-1;
     for(int i=2;i<=n;i+=2){
          ll x=one(i,i-1);
          if(x==n){
               ind=i-1;
               break;
          }
          if(x==n-1){
               x=one(i-1,i);
          }
          if(x==n){
               ind=i;
               break;
          }
     }
     if(ind==-1){
          ind=n;
     }
     ans[ind]=n;
     for(int i=1;i<=n;i++){
          if(i==ind) continue;
          ll x=two(i,ind);
          ans[i]=x;
     }
     cout<<"! ";
     for(int i=1;i<=n;i++){
          cout<<ans[i]<<" ";
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