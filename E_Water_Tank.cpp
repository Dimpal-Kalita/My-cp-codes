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


void dk(){
     ll n;
     cin>>n; 
     vl v(n);
     inp(v);
     stack<array<ll,3>>st;
     ll ans=0;
     rep(i,0,n){
          while(!st.empty() and st.top()[0]<=v[i]){
               st.pop();
          }
          ll ind=0;
          if(!st.empty()){
               ind=st.top()[1]+1;
               ans=(i-ind+1)*v[i]+st.top()[2];
          }else{
               ans=(i+1)*v[i]+1;
          }
          cout<<ans<<" ";
          st.push({v[i],i,ans});
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