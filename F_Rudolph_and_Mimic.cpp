/**
 * 
 * author: Dimpal Kalita
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
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





void secondstage(ll n,ll x){
     rep(i,0,n){
          ll y;
          cin>>y;
          if(y!=x){
               cout<<"! "<<i+1<<endl;
               return;
          }
     }
     cout<<"- 0"<<endl;
     rep(i,0,n){
          ll y;
          cin>>y;
          if(y!=x){
               cout<<"! "<<i+1<<endl;
               return;
          }
     }
     cout<<"- 0"<<endl;
     rep(i,0,n){
          ll y;
          cin>>y;
          if(y!=x){
               cout<<"! "<<i+1<<endl;
               return;
          }
     }
     return;
}
 
void preparesecondstage(ll x,ll n,vl v){
     vl temp;
     rep(i,0,n){
          if(v[i]!=x){
               temp.pb(i+1);
          }
     }
     cout<<"- "<<temp.size()<<" ";
     for(auto x:temp){
          cout<<x<<" ";
     }
     cout<<endl;
     secondstage(n-temp.size(),x);
     return;
}

void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     map<ll,ll>mp;
     for(auto x:v){
          mp[x]++;
     }
     cout<<"- 0"<<endl;
     inp(v);
     map<ll,ll>mp2;
     for(auto x:v){
          mp2[x]++;
     }
     for(auto x:v){
          if(mp2[x]>mp[x]){
               preparesecondstage(x,n,v);
               return;
          }
     }
     cout<<"- 0"<<endl;
     inp(v);
     mp2.clear();
     for(auto x:v){
          mp2[x]++;
     }
     for(auto x:v){
          if(mp2[x]>mp[x]){
               preparesecondstage(x,n,v);
               return;
          }
     } 
     return;
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