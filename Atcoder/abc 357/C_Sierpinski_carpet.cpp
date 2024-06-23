#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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



vector<string> ans(ll x){
     if(x==0){
           return {"#"};
     }
     ll n=pow(3,x),m=pow(3,x);
     ll a=pow(3,x-1),b=pow(3,x-1);
     vector<string> v(n,string(m,' '));
     vector<string> get=ans(x-1);
     for(int i=n/3;i<2*n/3;i++){
          for(int j=m/3;j<2*m/3;j++){
               v[i][j]='.';
          }
     }
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               if(v[i][j]!=' ') continue;
               v[i][j]=get[i%a][j%b];
          }
     }
     return v;
}

void dk(){
     ll n; 
     cin>>n;
     vector<string> v=ans(n);
     for(auto x: v){
          cout<<x<<endl;
     }
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   