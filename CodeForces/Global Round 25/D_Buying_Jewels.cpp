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
     ll n,k;
     cin>>n>>k;
     ll K=k,N=n;
     vl ans;
     for(ll i=0;i<=60;i++){
          if(k<=0 or n<=0) break;
          ll x=k;
          ll price=(n+x-1)/x;
          ll bought=min(k,n/price);
          ll spent= bought*price;
          n-=spent;
          k-=bought;
          ans.pb(price);
     }
     
     ll ct=0;
     for(auto i:ans){
          ll x=N/i;
          N-=(x*i);
          ct+=x;
     }
     if(K!=ct){
          cout<<"NO"<<endl;
          return;
     }
     cout<<"YES"<<endl;
     cout<<ans.size()<<endl;
     for(auto i:ans){
          cout<<i<<" ";
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