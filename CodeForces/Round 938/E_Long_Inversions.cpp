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
     string s;
     cin>>s;
     for(ll len=n;len>=0;len--){
          vector<ll>v(n+1,0);
          bool ok=0;
          for(ll i=0;i<n-len+1;i++){
               ok^=v[i];
               if(s[i]=='1' and ok){
                    ok^=1;
                    v[i+len]^=1;
               }
               if(s[i]=='0' and !ok){
                    ok^=1;
                    v[i+len]^=1;
               }
          }
          bool can=1;
          for(ll i=n-len+1;i<n;i++){
               ok^=v[i];
               if(s[i]=='1' and ok){
                    can=0;
                    break;
               }
               if(s[i]=='0' and !ok){
                    can=0;
                    break;
               }
          }
          if(can){
               cout<<len<<endl;
               return;
          }
     }
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