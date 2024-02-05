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
     ll lx=0,gx=0,ly=0,gy=0;
     rep(i,0,n){
          ll x,y;
          cin>>x>>y;
          if(x>0) gx++;
          else if(x<0) lx++;
          if(y>0) gy++;
          else if(y<0) ly++;
     }
     if(gx>0 && lx>0 && gy>0 && ly>0) cout<<"NO"<<endl;
     else cout<<"YES"<<endl;

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