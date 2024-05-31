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
     vector<vector<char>>v(2,vector<char>(n));
     for(int i=0;i<2;i++){
         for(int j=0;j<n;j++){
             cin>>v[i][j];
         }
     }
     ll ind=n-1;
     string ans="";
     ans+=v[0][0];
     ll cnt=1;
     ll mx=0;
     for(ll i=1;i<n;i++){
          if(v[0][i]==v[1][i-1]) ans+=v[0][i];
          else if(v[0][i]<v[1][i-1]){
               ans+=v[0][i];
               mx=max(mx,i);
          }else{
               ind=i;
               cnt=0;
               ans+=v[1][i-1];
               break;
          }
     }
     for(int i=ind;i<n;i++) ans+=v[1][i];
     cout<<ans<<endl;
     cout<<ind-mx+cnt<<endl;
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