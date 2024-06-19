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


vector<vl> all_subset(ll n){
     vector<vl>v;
     for(int i=0;i<(1<<n);i++){
          vl temp;
          for(int j=0;j<n;j++){
               if(i&(1<<j)) temp.pb(j);
          }
          v.pb(temp);
     }

     return v;
}


vector<string>v;
ll n,m;



void dk(){
     cin>>n>>m;
     rep(i,0,n){
          string x;
          cin>>x;
          v.pb(x);
     }      

     vector<vl> get=all_subset(n);

     ll ans=n;
     for(auto x:get){
          set<int>ind;
          for(auto i:x){
               for(int j=0;j<m;j++){
                    if(v[i][j]=='o') ind.insert(j);
               }
          }
          if(ind.size()==m){
               ans=min(ans,(ll)x.size());
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