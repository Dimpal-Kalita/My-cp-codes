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
     ll n,m;
     cin>>n>>m;
     ll mxx=0,mnx=n-1,mxy=0,mny=m-1;
     for(ll i=0;i<n;i++){
          for(ll j=0;j<m;j++){
               char x;
               cin>>x;
               if(x=='#'){
                    mxx=max(mxx,i);
                    mnx=min(mnx,i);
                    mxy=max(mxy,j);
                    mny=min(mny,j);
               }
          }
     }

     ll dia=max(mxx-mnx,mxy-mny);
     ll x=mnx+dia/2,y=mny+dia/2;
     cout<<x+1<<" "<<y+1<<endl;
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