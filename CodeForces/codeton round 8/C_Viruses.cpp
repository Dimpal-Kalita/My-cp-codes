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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n,m,q;
     cin>>n>>m>>q;
     vector<pair<pair<ll,ll>,pair<ll,string>>> p;
     rep(i,0,n){
          string s;
          cin>>s;
          ll c;
          cin>>c;
          ll pos;
          cin>>pos;
          p.pb({{pos,i},{c,s}});
     }
     sort(all(p));
     vector<pll>v;
     rep(i,0,m){
          ll vir,pos;
          cin>>vir>>pos;
          v.pb({pos,vir});
     }
     sort(all(v));
     map<ll,map<string,ll>>mp;
     rep(i,0,q){
          ll vir,c;
          string s;
          cin>>vir;
          cin>>s;
          cin>>c;
          mp[vir][s]=c;
     }
     ll ind=0;
     vector<ll>vis(n+1,0);
     for(auto i:v){
          while(ind<n and p[ind].F.F<=i.F){
               ind++;
          }
          for(ll j=ind-1;j>=0;j--){
               if(vis[j]) continue;
               if(mp[i.S][p[j].S.S]==0) continue;
               if(mp[i.S][p[j].S.S]<p[j].S.F){
                    p[j].S.F-=mp[i.S][p[j].S.S];
                    break;
               }
               if(mp[i.S][p[j].S.S]==p[j].S.F){
                    vis[j]=1;
                    break;
               }
               vis[j]=1;
          }
     }
     vector<pair<ll,string>>ans;
     for(ll i=0;i<n;i++){
          if(vis[i]==0) ans.pb({p[i].F.S,p[i].S.S});
     }

     sort(all(ans));
     cout<<sz(ans)<<endl;
     for(auto i:ans){
          cout<<i.S<<" ";
     }
     cout<<endl;
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