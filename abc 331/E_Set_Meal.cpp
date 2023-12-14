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
      ll n,m,l;
      cin>>n>>m>>l;
      vector<pll>ma,side;
      
      rep(i,0,n){
          ll x;
          cin>>x;
          ma.pb({x,i+1});
      }


      rep(i,0,m){
          ll x;
          cin>>x;
          side.pb({x,i+1});
      }
      sort(all(side),greater<pll>());

      map<pll,bool>mp;
      rep(i,0,l){
          ll x,y;
          cin>>x>>y;
          mp[{x,y}]=1;
      }
     
      ll ans=0;
      for(int i=0;i<n;i++){
          
          for(int j=0;j<m;j++){
               
                if(!mp.count({ma[i].S,side[j].S})){
                    ans=max(ma[i].F+side[j].F,ans);
                    break;
                }
          }

      }
     cout<<ans<<endl;
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