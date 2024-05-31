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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll a,b,c;
     cin>>a>>b>>c;
     ll leaf=(a+1);
     if(c!=leaf){
          cout<<-1<<endl;
          return;
     }
     if(a==0){
          cout<<b<<endl;
          return;
     }
     ll x=log2(a);
     ll val=(1<<x);
     ll rem=0;
     if((1<<x)!=a+1){
          a-=(1<<x);
          a++;
          rem=(1<<x)-a;
          b-=rem;
     }
     cout<<(b+c+leaf-1)/leaf+x<<endl;
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