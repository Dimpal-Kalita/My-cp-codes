/**
 * 
 * author: Dimpal Kalita
 * 
 */

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
     vector<lld> v(n);
     inp(v);
     sort(all(v));
     if(n==5){
          lld sum1=(v[0]+v[2])/(lld)2;
          lld sum2=(v[3]+v[4])/(lld)2;
          lld ans=sum2-sum1;
          sum1=(v[0]+v[1])/(lld)2;
          sum2=(v[2]+v[4])/(lld)2;
          ans=max(ans,sum2-sum1);
          cout<<fixed<<setprecision(10)<<ans<<endl;
          return;
     }
     lld x=(v[0]+v[1])*0.5;
     lld y=(v[n-1]+v[n-2])*0.5;
     lld ans=y-x;
     cout<<fixed<<setprecision(10)<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
      cout<<"Case #"<<i+1<<": ";
      dk();
   }
  return 0;
}