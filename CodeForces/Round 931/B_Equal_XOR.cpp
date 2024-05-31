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
     ll n,k;
     cin>>n>>k;
     vl v(2*n);
     inp(v);
     map<ll,ll>mp1,mp2;
     rep(i,0,n) mp1[v[i]]++;
     rep(i,n,2*n) mp2[v[i]]++;
     vl l,r;
     ll ct=0;
     k*=2;
     rep(i,1,n+1){
          if(mp1[i]==2 and k>1){
               l.pb(i);
               l.pb(i);
               k-=2;
               ct++;
          }
     }
     rep(i,1,n+1){
          if(mp2[i]==2 and ct){
               r.pb(i);
               r.pb(i);
               ct--;
          }
     }
     ct=0;
     rep(i,1,n+1){
          if(mp1[i]==1 and k){
               l.pb(i);
               k--;
               ct++;
          }
     }
     rep(i,1,n+1){
          if(mp2[i]==1 and ct){
               r.pb(i);
               ct--;
          }
     }
     for(auto i:l){
          cout<<i<<" ";
     }
     cout<<endl;
     for(auto i:r){
          cout<<i<<" ";
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