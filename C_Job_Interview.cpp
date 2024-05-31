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
     ll n,m;
     cin>>n>>m;
     ll N=n+m+1;
     vl a(N),b(N);
     inp(a);
     inp(b);
     multiset<pll> p;
     rep(i,0,N){
          p.insert({a[i]-b[i],a[i]});
     }
     multiset<pll> curp,curt;
     ll sum=0;
     // debug(p,t);
     rep(i,0,N){
          if(curp.find({a[i]-b[i],a[i]})!=curp.end()){
               sum-=a[i];
               curp.erase(curp.find({a[i]-b[i],a[i]}));
          }
          if(curt.find({b[i]-a[i],b[i]})!=curt.end()){
               sum-=b[i];
               curt.erase(curt.find({b[i]-a[i],b[i]}));
          }
          if(p.find({a[i]-b[i],a[i]})!=p.end()){
               p.erase(p.find({a[i]-b[i],a[i]}));
          }
          while(curp.size()<n){
               curp.insert(*p.rbegin());
               sum+=p.rbegin()->S;
               p.erase(p.find(*p.rbegin()));
          }
          while(curt.size()<m){
               auto it=*p.begin();
               curt.insert({it.F*-1,a[i]});
               sum+=p.begin()->S;
               p.erase(p.find(*p.begin()));
          }
          debug(curp,curt);
          cout<<sum<<" ";
          curp.insert({a[i]-b[i],a[i]});
          curt.insert({b[i]-a[i],b[i]});
          sum+=a[i];
          sum+=b[i];
          if(curp.size()>n){
               sum-=curp.begin()->S;
               auto val=*curp.begin();
               curp.erase(curp.begin());
               p.insert(val);
          }
          if(curt.size()>m){
               sum-=curt.begin()->S;
               auto val=*curt.begin();
               curt.erase(curt.begin());
               p.insert({val.F*-1,val.S});
          }
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