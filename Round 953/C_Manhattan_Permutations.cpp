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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n,k;
     cin>>n>>k;
     vl vis(n+1,0);
     vl ans(n);
     iota(all(ans),1);
     if(k%2){
          cout<<"No"<<endl;
          return;
     } 
     // debug(ans);
     for(int i=0;i<=n/2;i++){
          ll x=min(k,2*(n-2*i-1));
          // cout<<x<<endl;
          x/=2;
          if(vis[i+x] || vis[i]) continue;
          vis[i]=1;
          vis[i+x]=1;
          swap(ans[i],ans[i+x]);
          k-=2*x;
     }
     // debug(ans);
     if(k){
          cout<<"No"<<endl;
          return;
     }
     cout<<"Yes"<<endl;
     for(auto i:ans) cout<<i<<" ";
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