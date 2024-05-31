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
     inp(v);
     ll sum=accumulate(all(v),0LL);
     ll minsum=sum,ct=0,cur=0;
     for(int i=0;i<n;i++){
         if(cur>0){
             minsum=min(minsum,cur+v[i]);
             cur=v[i];
             ct=1;
         }else{
          cur+=v[i];
          ct++;
         }
         if(ct>=2){
               minsum=min(minsum,cur);
         }
     }
     if(n==1){
          cout<<v[0]<<"\n";
          return;
     }
     for(int i=0;i<n-1;i++){
          minsum=min(minsum,v[i]+v[i+1]);
     }
     for(int i=0;i<n-2;i++){
          minsum=min(minsum,v[i]+v[i+1]+v[i+2]);
     }
     ll extra=sum-minsum;
     cout<<abs(extra)+abs(minsum)<<"\n";
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