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

     auto calc=[&](string s){
          ll ans=0,ct=0;
          for(auto i:s){
               if(ct==0 and i=='0') continue;
               ct++;
               if(ct==3){
                    ans++;
                    ct=0;
               }
          }
          if(ct) ans++;
          return ans;
     };
     string s;
     cin>>s;
     ll ans=0;
     for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
               string t=s.substr(i,j-i+1);
               ans+=calc(t);
          }
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