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


vector<vl> sub(ll n){
     vector<vl>ans;
     for(int i=0;i<(1<<n);i++){
         vl v(n);
         for(int j=0;j<n;j++){
             if(i&(1<<j)) v[j]=1;
         }
         ans.pb(v);
     }
     return ans;
}

void dk(){
     ll  n,m,k;
     cin>>n>>m>>k;
     vector<vl>get=sub(n);
     vector<pair<vl,char>>v;
     rep(i,0,m){
          ll sz;
          cin>>sz;
          vl temp(sz);
          inp(temp);
          char c;
          cin>>c;
          v.pb({temp,c});
     }
     ll ans=0;
     for(auto vis:get){
          bool flag=1;
          rep(i,0,m){
               ll cnt=0;
               for(auto j:v[i].F){
                    if(vis[j-1]==1) cnt++; 
               }
               if((cnt<k and v[i].S=='o') or(cnt>=k and v[i].S=='x')){
                    flag=0;
               }
          }
          if(flag) ans++;
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