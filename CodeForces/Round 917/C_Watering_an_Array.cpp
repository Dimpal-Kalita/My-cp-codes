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


ll check(vl v){
     ll n=v.size();
     ll ans=0;
     for(int i=0;i<n;i++){
          if(v[i]==i+1) ans++;
     }
     return ans;
}
void dk(){
     ll n,k,d;
     cin>>n>>k>>d;
     vl v(n);
     inp(v); 
     vl vp(k);
     inp(vp);
     
     ll ans=check(v)+(d-1)/2;
     if(d==1){
          cout<<ans<<endl;
          return;
     }
     for(int i=0;i<=2*n and i+2<=d;i++){
          ll ind=i%k;
          for(int j=0;j<vp[ind];j++){
               v[j]++;
          }
          ans=max(ans,check(v)+(d-i-2)/2);
     }
     cout<<ans<<endl;
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