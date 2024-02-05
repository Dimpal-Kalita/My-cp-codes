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

// #ifndef ONLINE_JUDGE
// #include ".vscode/debug.hpp";
// #else
// #define debug(...)
// #define debugArr(arr, n)
// #endif



void dk(){
     ll n,q;
     cin>>n>>q;
     vl v(n);
     inp(v);
     map<pll,vl>store,ps,calc;
     for(int i=1;i*i<=n;i++){
          for(ll k=0;k<i;k++){
               vl temp1={0},temp2={0};
               ll ind=1,sum1=0,sum2=0;
               for(ll j=k;j<n;j+=i){
                    temp1.pb((sum1+=v[j]));
                    temp2.pb((sum2+=v[j]*(ind++))); 
               }
               ps[{i,k}]=temp1;
               calc[{i,k}]=temp2;
          }
     } 
     // debug(store);
     // debug(ps);
     // debug(calc);
     ll sq=sqrt(n);
     while(q--){
          ll s,d,k;
          cin>>s>>d>>k;
          s--;
          if(d>sq){
               ll ans=0,ind=1;
               for(int i=s;i<n;i+=d){
                    ans+=v[i]*ind++;
                    if(ind>k) break;
               }
               cout<<ans<<" ";
               continue;
          }
          // cout<<d<<" "<<s%d<<" "<<((s/d)+k)<<endl;
          cout<<calc[{d,s%d}][s/d+k]-calc[{d,s%d}][s/d]-(s/d)*(ps[{d,s%d}][s/d+k]-ps[{d,s%d}][s/d])<<" ";
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