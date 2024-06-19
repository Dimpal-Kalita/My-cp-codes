#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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
      ll x,y,z,k;
      cin>>x>>y>>z>>k;
      ll cb=cbrt(k);
      ll ans=0;
      for(ll a=1;a<=cb;a++){
           if(k%a==0){
                ll bc=k/a;
                ll sq=sqrt(bc);
                for(ll b=1;b<=sq;b++){
                     if(bc%b==0){
                         ll c=bc/b;
                         ans=max(ans,(max(0LL,x-a+1))*(max(0LL,y-b+1))*(max(0LL,z-c+1)));
                         ans=max(ans,(max(0LL,x-a+1))*(max(0LL,y-c+1))*(max(0LL,z-b+1)));
                         ans=max(ans,(max(0LL,x-b+1))*(max(0LL,y-a+1))*(max(0LL,z-c+1)));
                         ans=max(ans,(max(0LL,x-b+1))*(max(0LL,y-c+1))*(max(0LL,z-a+1)));
                         ans=max(ans,(max(0LL,x-c+1))*(max(0LL,y-a+1))*(max(0LL,z-b+1)));
                         ans=max(ans,(max(0LL,x-c+1))*(max(0LL,y-b+1))*(max(0LL,z-a+1))); 
                     }
                }
           }
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