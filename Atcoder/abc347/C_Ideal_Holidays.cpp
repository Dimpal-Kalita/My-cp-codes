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
     ll n,a,b;
     cin>>n>>a>>b;
     vl v(n);
     bool first=1,second=1;
     set<ll>st;
     for(auto &it:v){
          cin>>it;
          it%=(a+b);
          st.insert(it);
     }
     v=vector<ll>(all(st));
     v.pb(v[0]+a+b);
     rep(i,0,sz(v)-1){
          if((v[i+1]-v[i]-1)>=b){
               cout<<"Yes";
               return;
          }
     }
     cout<<"No";
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