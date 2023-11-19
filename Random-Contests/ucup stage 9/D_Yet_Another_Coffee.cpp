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
     ll n,m;
     cin>>n>>m;
     vl v(n);
     inp(v); 
     ll ans=0;
     map<ll,ll>mp;
     rep(i,0,m){
          ll x,y;
          cin>>x>>y;
          mp[x]+=y;
     }
     ll i=0,mn=1e9,ind=0;
     for(auto [x,y]:mp){
          while(i<=(x-1)){
               if(v[i]<v[ind]){
                    ind=i;
               }
               i++;
          }
          v[ind]-=y;
     }
     sort(all(v));
     ll sum=0;
     for(auto i:v){
          sum+=i;
          cout<<sum<<" ";
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