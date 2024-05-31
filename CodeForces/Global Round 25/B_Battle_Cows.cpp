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




ll calc(ll ind,ll k,vl v){
     ll cur=0;
     ll n=v.size();
     swap(v[ind],v[k]);

     ll last=v[0];
     for(int i=1;i<n;i++){
          if(v[i]>v[ind]) break;
          if(v[i]>last){
               cur=1;
               last=v[i];
          }else{
               cur++;
          }
     }
     return (last==v[ind]?cur:0);
}

void dk(){
     ll n,k;
     cin>>n>>k;
     vl v(n);
     inp(v);
     ll x=v[k-1];
     ll ind=k-1;
     for(int i=0;i<k;i++){
          if(v[i]>=x){
               ind=i;
               break;
          }
     }
     ll ans1=calc(ind,k-1,v);
     ll ans2=calc(k-1,k-1,v);
     ll ans=calc(0,k-1,v);
     cout<<max({ans1,ans2,ans})<<endl;
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