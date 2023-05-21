/**
 * 
 * author: Dimpal Kalita
 * date: 19/05/2023 20:20:44
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


bool check1(vector<ll>&v){
     for(auto it:v){
          if(it%2) return 0;
     }
     return 1;
}


void dk(){
      ll n;
      cin>>n;
      vector<ll> v(n);
      inp(v);
      if(check1(v)){
          cout<<"YES"<<endl;
          return;
      }
      ll mn1=1e18,mn2=1e18;
      for(auto it:v){
          if(it%2==0)   mn1=min(mn1,it);
          if(it%2==1)   mn2=min(mn2,it);
      }

      if(mn2<mn1){
          cout<<"YES"<<endl;
          return;
      }
      cout<<"NO"<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}