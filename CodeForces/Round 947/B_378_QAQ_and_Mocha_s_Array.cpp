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
     vl v(n);
     map<ll,ll>mp;
     inp(v);
     sort(all(v));
     ll x=v[0],y=0;
     vector<ll>vis(n+1);
     rep(i,0,n){
          vis[i]=1;
          if(v[i]%x){
               y=v[i];
               break;
          }
     }
     rep(i,0,n){
          if(vis[i]) continue;
          if(v[i]%y==0 or v[i]%x==0) vis[i]=1;
     }
     rep(i,0,n){
          if(!vis[i]){
               cout<<"No"<<endl;
               return;
          }
     }
     cout<<"Yes"<<endl;
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