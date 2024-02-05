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
     vl v(n);
     inp(v);
     if(k>=3){
          cout<<0<<endl;
          return;
     }
     sort(all(v));
     ll mn=v[0];
     vl vp;
     for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
               mn=min(mn,abs(v[i]-v[j]));
               vp.pb(abs(v[i]-v[j]));
          }
     }

     if(k==1){
          cout<<mn<<endl;
          return; 
     }

     for(auto i:vp){
          ll ind=upper_bound(all(v),i)-v.begin();

          for(int j=max(ind-2,0LL);j<=min(ind+2,n-1);j++){
               mn=min(mn,abs(i-v[j]));
          }
          ind=lower_bound(all(v),i)-v.begin();
          for(int j=max(ind-2,0LL);j<=min(ind+2,n-1);j++){
               mn=min(mn,abs(i-v[j]));
          }
     }
     cout<<mn<<endl;
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