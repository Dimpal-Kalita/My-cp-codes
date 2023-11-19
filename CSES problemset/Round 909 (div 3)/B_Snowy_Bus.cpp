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
     ll n,w;
     cin>>n>>w;
     vector<pair<ll,pll>>vp(n);
     rep(i,0,n){
          cin>>vp[i].S.F;
          w+=vp[i].S.F;
     } 
     rep(i,0,n){
          cin>>vp[i].S.S;
          vp[i].F=vp[i].S.S*vp[i].S.F;
     }
     sort(all(vp),greater<pair<ll,pll>>());
     ll ans=0;
     ll f=0;
     ll W=w;
     for(auto i:vp){
          w-=i.S.F;
          f+=i.S.S;
          ans++;
          if(w<=f){
               break;
          }
     }
     if(w>f){
          cout<<-1<<endl;
          return;
     }
     w=W;
     f=0;
     ll ans2=0;
     rep(i,0,n){
          vp[i].F=vp[i].S.S;
     }
     sort(all(vp),greater<pair<ll,pll>>());
     for(auto i:vp){
          w-=i.S.F;
          f+=i.S.S;
          ans2++;
          if(w<=f){
               break;
          }
     }
     w=W;
     f=0;
     ll ans3=0;
     rep(i,0,n){
          vp[i].F=vp[i].S.F;
     }
     sort(all(vp),greater<pair<ll,pll>>());
     for(auto i:vp){
          w-=i.S.F;
          f+=i.S.S;
          ans3++;
          if(w<=f){
               break;
          }
     }
     w=W;
     f=0;
     ll ans4=0;
     rep(i,0,n){
          vp[i].F=vp[i].S.F+vp[i].S.S;
     }
     sort(all(vp),greater<pair<ll,pll>>());
     for(auto i:vp){
          w-=i.S.F;
          f+=i.S.S;
          ans4++;
          if(w<=f){
               break;
          }
     }
     cout<<min({ans,ans2,ans3,ans4})<<endl;
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